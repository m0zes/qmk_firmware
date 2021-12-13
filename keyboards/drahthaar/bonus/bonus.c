/* Copyright 2021 Nick Brassel (@tzarc)
 * Copyright 2021 Adam Tygart (@m0zes)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <quantum.h>
#include <hal_pal.h>

#include "bonus.h"

void board_init(void) { usbpd_init(); }

const char* usbpd_str(usbpd_allowance_t allowance) {
    switch (allowance) {
        case USBPD_500MA:
            return "500mA";
        case USBPD_1500MA:
            return "1500mA";
        case USBPD_3000MA:
            return "3000mA";
        default:
            return "500mA";
    }
}

static usbpd_allowance_t usbpd_current_setting = USBPD_500MA;

void usbpd_update(void) {
    static uint32_t last_read = 0;
    if (timer_elapsed32(last_read) > 250) {
        last_read = timer_read32();
        switch (usbpd_get_allowance()) {
            case USBPD_500MA:
                if (usbpd_current_setting != USBPD_500MA) {
                    dprintf("Transitioning UCPD1 %s -> %s\n", usbpd_str(usbpd_current_setting), usbpd_str(USBPD_500MA));
                    usbpd_current_setting = USBPD_500MA;
                }
                break;
            case USBPD_1500MA:
                if (usbpd_current_setting != USBPD_1500MA) {
                    dprintf("Transitioning UCPD1 %s -> %s\n", usbpd_str(usbpd_current_setting), usbpd_str(USBPD_1500MA));
                    usbpd_current_setting = USBPD_1500MA;
                }
                break;
            case USBPD_3000MA:
                if (usbpd_current_setting != USBPD_3000MA) {
                    dprintf("Transitioning UCPD1 %s -> %s\n", usbpd_str(usbpd_current_setting), usbpd_str(USBPD_3000MA));
                    usbpd_current_setting = USBPD_3000MA;
                }
                break;
        }
    }
}

void kb_state_update(void) {
    usbpd_update();
}

void housekeeping_task_kb(void) {
    // Work out if we've changed our current limit, update the limiter circuit switches
    static uint8_t current_setting = USBPD_500MA;
    if (current_setting != usbpd_current_setting) {
        current_setting = usbpd_current_setting;
        switch (current_setting) {
            default:
            case USBPD_500MA:
                writePinLow(RGB_CURR_1500mA_OK_PIN);
                writePinLow(RGB_CURR_3000mA_OK_PIN);
                break;
#ifdef BONUS_SUPPORTS_3A_FUSE
            case USBPD_1500MA:
                writePinHigh(RGB_CURR_1500mA_OK_PIN);
                writePinLow(RGB_CURR_3000mA_OK_PIN);
                break;
            case USBPD_3000MA:
                writePinHigh(RGB_CURR_1500mA_OK_PIN);
                writePinHigh(RGB_CURR_3000mA_OK_PIN);
                break;
#else
            case USBPD_1500MA:
            case USBPD_3000MA:
                writePinHigh(RGB_CURR_1500mA_OK_PIN);
                writePinLow(RGB_CURR_3000mA_OK_PIN);
                break;
#endif
        }

        // Toggle rgblight on and off, if it's already on, to force a brightness update on all LEDs
        if (rgblight_is_enabled()) {
            rgblight_disable_noeeprom();
            rgblight_enable_noeeprom();
        }
    }
}

//----------------------------------------------------------
// Initialisation

void keyboard_post_init_kb(void) {
    // Turn off increased current limits
    setPinOutput(RGB_CURR_1500mA_OK_PIN);
    writePinLow(RGB_CURR_1500mA_OK_PIN);
    setPinOutput(RGB_CURR_3000mA_OK_PIN);
    writePinLow(RGB_CURR_3000mA_OK_PIN);

    // Turn on the RGB
    setPinOutput(RGB_POWER_ENABLE_PIN);
    writePinHigh(RGB_POWER_ENABLE_PIN);

    // Allow for user post-init
    keyboard_post_init_user();
}

#if defined(RGB_MATRIX_ENABLE)
#    define rgb_to_hsv_hook_func rgb_matrix_hsv_to_rgb
#elif defined(RGBLIGHT_ENABLE)
#    define rgb_to_hsv_hook_func rgblight_hsv_to_rgb
#endif
RGB rgb_to_hsv_hook_func(HSV hsv) {
    float scale;
    switch (usbpd_current_setting) {
        default:
        case USBPD_500MA:
            scale = 0.35f;
            break;
#ifdef BONUS_SUPPORTS_3A_FUSE
        case USBPD_1500MA:
            scale = 0.75f;
            break;
        case USBPD_3000MA:
            scale = 1.0f;
            break;
#else
        case USBPD_1500MA:
        case USBPD_3000MA:
            scale = 0.75f;
            break;
#endif
    }

    hsv.v = (uint8_t)(hsv.v * scale);
    return hsv_to_rgb(hsv);
}
