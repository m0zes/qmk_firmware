MCU = STM32G474

BOOTMAGIC_ENABLE = yes		# Virtual DIP switch configuration
MOUSEKEY_ENABLE = no		# Mouse keys
EXTRAKEY_ENABLE = yes		# Audio control and System control
CONSOLE_ENABLE = no		# Console for debug
COMMAND_ENABLE = no		# Commands for debug and configuration
SLEEP_LED_ENABLE = no		# Breathing sleep LED during USB suspend
NKRO_ENABLE = yes		# USB Nkey Rollover
UNICODE_ENABLE = no		# Unicode
WPM_ENABLE = yes

USBPD_ENABLE = yes

WS2812_DRIVER = pwm
CIE1931_CURVE = yes

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

EEPROM_DRIVER = spi

USE_FPU = yes
LTO_ENABLE = yes
OPT = 2

DEFAULT_FOLDER = drahthaar/bonus/rev1
