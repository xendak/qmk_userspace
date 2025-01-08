# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ORYX_ENABLE = no
# KEYBOARD_SHARED_EP = yes
SPACE_CADET_ENABLE = no
# DEBOUNCE_TYPE = sym_eager_pk

LTO_ENABLE = yes
OPT = fast

SRC += achordion/achordion.c

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_CUSTOM_USER = yes
AUDIO_ENABLE = no
COMBO_ENABLE = yes
LEADER_ENABLE = no
STENO_ENABLE = no
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = no


VPATH += keyboards/gboards
