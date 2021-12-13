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
        { 0,  1,  2,  3  },
        { 4,  5,  6,  7  },
        { 8,  9,  10, 11 },
        { 12, 13, 14 },
        { 15, 16, 17, 18 },
        { 19,     20 }
    }, {
        { 53,  10  }, { 96,  10  }, { 139, 10  }, { 181, 10  },
        { 53,  23  }, { 96,  23  }, { 139, 23  }, { 181, 23  },
        { 53,  29  }, { 96,  29  }, { 139, 29  }, { 192, 33  },
        { 53,  39  }, { 96,  39  }, { 139, 39  },
        { 53,  50  }, { 96,  50  }, { 139, 50  }, { 192, 52  },
        { 75,  58  },               { 139, 58  },
    }, {
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,                    LED_FLAG_KEYLIGHT
    }
};
// clang-format on
#endif  // RGB_MATRIX_ENABLE
