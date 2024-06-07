# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ORYX_ENABLE = no
# KEYBOARD_SHARED_EP = yes
SPACE_CADET_ENABLE = no
# DEBOUNCE_TYPE = sym_eager_pk

SRC = matrix.c
SRC += features/achordion.c
# SRC += sequence_transform/sequence_transform.c
# SRC += sequence_transform/utils.c

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_CUSTOM_USER = yes
AUDIO_ENABLE = no
COMBO_ENABLE = yes
LEADER_ENABLE = no
STENO_ENABLE = no
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes

VPATH += keyboards/gboards
