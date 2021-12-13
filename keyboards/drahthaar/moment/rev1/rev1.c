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

#include <hal.h>
#include <quantum.h>
#include "rev1.h"

// Delays can be shorter than 30us.
void matrix_io_delay(void) {
    for (int i = 0; i < 10; ++i) __asm__ volatile("nop\nnop\nnop\n");
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        { 0,      1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32 },
        { 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 },
        { 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,     62             },
        { 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,         74,     75     },
        { 76, 77, 78,         79,             80, 81, 82,     83, 84, 85, 86 },
    }, {
        { 14,  12  },               { 37,  12  }, { 48,  12  }, { 60,  12  }, { 71,  12  }, { 88,  12  }, { 99,  12  }, { 113, 12  }, { 125, 12  }, { 142, 12  }, { 153, 12  }, { 164, 12  }, { 176, 12  }, { 190, 12  }, { 204, 12  }, { 215, 12  },
        { 14,  25  }, { 26,  25  }, { 37,  25  }, { 48,  25  }, { 60,  25  }, { 71,  25  }, { 82,  25  }, { 94,  25  }, { 108, 25  }, { 119, 25  }, { 130, 25  }, { 142, 25  }, { 153, 25  }, { 170, 25  }, { 190, 25  }, { 204, 25  }, { 215, 25  }, 
        { 17,  33  }, { 31,  33  }, { 43,  33  }, { 54,  33  }, { 65,  33  }, { 77,  33  }, { 88,  33  }, { 99,  33  }, { 113, 33  }, { 125, 33  }, { 136, 33  }, { 147, 33  }, { 159, 33  }, { 173, 33  }, { 190, 33  }, { 204, 33  }, { 215, 33  }, 
        { 17,  41  }, { 34,  41  }, { 45,  41  }, { 57,  41  }, { 68,  41  }, { 79,  41  }, { 91,  41  }, { 102, 41  }, { 116, 41  }, { 128, 41  }, { 139, 41  }, { 150, 41  },               { 170, 41  }, 
        { 20,  50  }, { 40,  50  }, { 51,  50  }, { 62,  50  }, { 74,  50  }, { 85,  50  }, { 96,  50  }, { 111, 50  }, { 122, 50  }, { 133, 50  }, { 145, 50  },                             { 167, 50  },               { 204, 50  }, 
        { 14,  58  }, { 28,  58  }, { 43,  58  },                             { 88,  58  },                                           { 130, 58  }, { 145, 58  }, { 162, 58  },               { 176, 58  }, { 190, 58  }, { 204, 58  }, { 215, 58  }
    }, {
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};
// clang-format on
#endif  // RGB_MATRIX_ENABLE
