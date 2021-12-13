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

#pragma once

// RGB configuration
#define RGB_POWER_ENABLE_PIN B0
#define RGB_CURR_1500mA_OK_PIN C5
#define RGB_CURR_3000mA_OK_PIN C4
#define RGBLED_NUM 21

// EEPROM configuration
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN B5
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 8  // (160MHz/8) => 20MHz
#define EXTERNAL_EEPROM_BYTE_COUNT 8192
#define EXTERNAL_EEPROM_PAGE_SIZE 64  // it's FRAM, so it doesn't actually matter, this just sets the RAM buffer

// Fault indicators
#define BOARD_POWER_FAULT_PIN C9
#define RGB_POWER_FAULT_PIN C4
