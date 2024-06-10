# This file should be included in user layout's rules.mk file
all: st_build

st_build:
	python3 $(mkfile_dir)/tt/generator/sequence_transform_data.py

LIB_SRC += tt/sequence_transform.c
LIB_SRC += tt/utils.c
LIB_SRC += tt/trie.c
LIB_SRC += tt/keybuffer.c
LIB_SRC += tt/cursor.c
LIB_SRC += tt/key_stack.c
LIB_SRC += tt/triecodes.c
LIB_SRC += tt/predicates.c
LIB_SRC += tt/st_debug.c
