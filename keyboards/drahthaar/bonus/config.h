/* Copyright 2021 Adam Tygart (@m0zes)
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

#pragma once

#include "config_common.h"

// USB Device parameters
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x7784
#define DEVICE_VER 0x0001
#define MANUFACTURER drahthaar
#define PRODUCT Bonus

// Matrix
#define MATRIX_ROWS 6
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5 }
#define MATRIX_COL_PINS { A6, A7, C0, C1 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

// Bootloader
#define STM32_BOOTLOADER_DUAL_BANK TRUE
#define STM32_BOOTLOADER_DUAL_BANK_GPIO B7

// SPI Configuration
#define SPI_DRIVER SPID3
#define SPI_SCK_PIN C10
#define SPI_SCK_PAL_MODE 6
#define SPI_MOSI_PIN C12
#define SPI_MOSI_PAL_MODE 6
#define SPI_MISO_PIN C11
#define SPI_MISO_PAL_MODE 6

// RGB configuration
#define WS2812_EXTERNAL_PULLUP
#define RGB_DI_PIN B2
#ifdef RGB_MATRIX_ENABLE
#define DRIVER_LED_TOTAL RGBLED_NUM
#endif  //  RGB_MATRIX_ENABLE
#define WS2812_PWM_DRIVER PWMD20
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 3
#define WS2812_DMA_STREAM STM32_DMA1_STREAM1
#define WS2812_DMA_CHANNEL 1
#define WS2812_DMAMUX_ID STM32_DMAMUX1_TIM20_UP

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
