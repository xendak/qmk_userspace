// Copyright 2025 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// This was file generated on 2025-07-23 14:39:52.
// Do not edit this file directly!

#pragma once

#define SEQUENCE_TRANSFORM_GENERATOR_VERSION_3_2

#define TRIECODE_SEQUENCE_TOKEN_0 0x0080
#define TRIECODE_SEQUENCE_METACHAR_0 0x00A0
#define TRIECODE_SEQUENCE_REF_TOKEN_0 0x0080
#define SEQUENCE_MIN_LENGTH 2 // "zl"
#define SEQUENCE_MAX_LENGTH 8 // "theyre'⎵"
#define TRANSFORM_MAX_LENGTH 8 // "they're⎵"
#define COMPLETION_MAX_LENGTH 4
#define MAX_BACKSPACES 2
#define SEQUENCE_TRIE_SIZE 537
#define COMPLETIONS_SIZE 28
#define SEQUENCE_TOKEN_COUNT 4
#define SEQUENCE_METACHAR_COUNT 8
#define SEQUENCE_REF_TOKEN_COUNT 8

static const char st_seq_token_ascii_chars[] = { '*', '@', '#', '&' };
#ifdef ST_TESTER
static const char *st_seq_tokens[] = { "👆", "👈", "★", "👍" };
static const char *st_seq_metachars[] = { "∆", "∇", "∂", "‼", "‥", "•", "‸", "∀" };
static const char *st_trans_seq_ref_tokens[] = { "◯", "⑴", "⑵", "⑶", "⑷", "⑸", "⑹", "⑺" };
static const char *st_space_token = "⎵";
#endif

// Sequence Transformation dictionary with longest match semantics
// Dictionary (44 entries):
//    zl       -> zil
//    zn       -> zin
//    zg       -> zig
//    zm       -> zim
//    mz       -> my
//    my       -> mz
//    kz       -> ky
//    ky       -> kz
//    qe       -> que
//    qa       -> qua
//    qi       -> qui
//    qo       -> quo
//    zzl      -> zzl
//    zze      -> ize
//    quu      -> qu
//    qaa      -> qa
//    qee      -> qe
//    qii      -> qi
//    qoo      -> qo
//    qqe      -> quee
//    wont⎵    -> won't⎵
//    cant⎵    -> can't⎵
//    dont⎵    -> don't⎵
//    Wont⎵    -> Won't⎵
//    Cant⎵    -> Can't⎵
//    Dont⎵    -> Don't⎵
//    didnt⎵   -> didn't⎵
//    youre⎵   -> you're⎵
//    Didnt⎵   -> Didn't⎵
//    Youre⎵   -> You're⎵
//    wont'⎵   -> wont⎵
//    cant'⎵   -> cant⎵
//    dont'⎵   -> dont⎵
//    Wont'⎵   -> Wont⎵
//    Cant'⎵   -> Cant⎵
//    Dont'⎵   -> Dont⎵
//    theyre⎵  -> they're⎵
//    Theyre⎵  -> They're⎵
//    didnt'⎵  -> didnt⎵
//    youre'⎵  -> youre⎵
//    Didnt'⎵  -> Didnt⎵
//    Youre'⎵  -> Youre⎵
//    theyre'⎵ -> theyre⎵
//    Theyre'⎵ -> Theyre⎵

static const uint8_t sequence_transform_trie[SEQUENCE_TRIE_SIZE] PROGMEM = {
    0x40, 0x20, 0x00, 0x32, 0x61, 0x01, 0x5F, 0x65, 0x01, 0x6E, 0x67, 0x01, 0x92, 0x69, 0x01, 0x9A,
    0x6C, 0x01, 0xA9, 0x6D, 0x01, 0xB9, 0x6E, 0x01, 0xC1, 0x6F, 0x01, 0xC9, 0x75, 0x01, 0xD8, 0x79,
    0x01, 0xE1, 0x7A, 0x01, 0xF3, 0x80, 0x02, 0x05, 0x81, 0x02, 0x0A, 0x82, 0x02, 0x0F, 0x83, 0x02,
    0x14, 0x00, 0x40, 0x27, 0x00, 0x3D, 0x65, 0x00, 0xD2, 0x74, 0x01, 0x08, 0x00, 0x40, 0x65, 0x00,
    0x45, 0x74, 0x00, 0x7B, 0x00, 0x01, 0x72, 0x00, 0x40, 0x75, 0x00, 0x50, 0x79, 0x00, 0x65, 0x00,
    0x01, 0x6F, 0x00, 0x40, 0x59, 0x00, 0x5B, 0x79, 0x00, 0x60, 0x00, 0xA0, 0x01, 0x01, 0x00, 0x03,
    0xA0, 0x01, 0x01, 0x00, 0x03, 0x01, 0x65, 0x68, 0x00, 0x40, 0x54, 0x00, 0x71, 0x74, 0x00, 0x76,
    0x00, 0xA0, 0x01, 0x01, 0x00, 0x03, 0xA0, 0x01, 0x01, 0x00, 0x03, 0x01, 0x6E, 0x00, 0x40, 0x61,
    0x00, 0x89, 0x64, 0x00, 0x9B, 0x6F, 0x00, 0xB0, 0x00, 0x40, 0x43, 0x00, 0x91, 0x63, 0x00, 0x96,
    0x00, 0xA0, 0x01, 0x01, 0x00, 0x03, 0xA0, 0x01, 0x01, 0x00, 0x03, 0x01, 0x69, 0x00, 0x40, 0x44,
    0x00, 0xA6, 0x64, 0x00, 0xAB, 0x00, 0xA0, 0x01, 0x01, 0x00, 0x03, 0xA0, 0x01, 0x01, 0x00, 0x03,
    0x40, 0x44, 0x00, 0xBE, 0x57, 0x00, 0xC3, 0x64, 0x00, 0xC8, 0x77, 0x00, 0xCD, 0x00, 0xA0, 0x01,
    0x01, 0x00, 0x03, 0xA0, 0x01, 0x01, 0x00, 0x03, 0xA0, 0x01, 0x01, 0x00, 0x03, 0xA0, 0x01, 0x01,
    0x00, 0x03, 0x01, 0x72, 0x00, 0x40, 0x75, 0x00, 0xDD, 0x79, 0x00, 0xF2, 0x00, 0x01, 0x6F, 0x00,
    0x40, 0x59, 0x00, 0xE8, 0x79, 0x00, 0xED, 0x00, 0xA0, 0x02, 0x04, 0x00, 0x00, 0xA0, 0x02, 0x04,
    0x00, 0x00, 0x01, 0x65, 0x68, 0x00, 0x40, 0x54, 0x00, 0xFE, 0x74, 0x01, 0x03, 0x00, 0xA0, 0x02,
    0x04, 0x00, 0x00, 0xA0, 0x02, 0x04, 0x00, 0x00, 0x01, 0x6E, 0x00, 0x40, 0x61, 0x01, 0x16, 0x64,
    0x01, 0x28, 0x6F, 0x01, 0x3D, 0x00, 0x40, 0x43, 0x01, 0x1E, 0x63, 0x01, 0x23, 0x00, 0xA0, 0x01,
    0x03, 0x00, 0x04, 0xA0, 0x01, 0x03, 0x00, 0x04, 0x01, 0x69, 0x00, 0x40, 0x44, 0x01, 0x33, 0x64,
    0x01, 0x38, 0x00, 0xA0, 0x01, 0x03, 0x00, 0x04, 0xA0, 0x01, 0x03, 0x00, 0x04, 0x40, 0x44, 0x01,
    0x4B, 0x57, 0x01, 0x50, 0x64, 0x01, 0x55, 0x77, 0x01, 0x5A, 0x00, 0xA0, 0x01, 0x03, 0x00, 0x04,
    0xA0, 0x01, 0x03, 0x00, 0x04, 0xA0, 0x01, 0x03, 0x00, 0x04, 0xA0, 0x01, 0x03, 0x00, 0x04, 0xC1,
    0x01, 0x6A, 0x42, 0x01, 0x00, 0x16, 0x01, 0x71, 0x00, 0xA0, 0x40, 0x02, 0x00, 0x15, 0xC1, 0x01,
    0x7E, 0x42, 0x01, 0x00, 0x02, 0x40, 0x71, 0x01, 0x7D, 0x7A, 0x01, 0x8A, 0x00, 0xE0, 0xC0, 0x02,
    0x00, 0x0A, 0x01, 0x71, 0x00, 0xA0, 0x41, 0x03, 0x00, 0x0A, 0x01, 0x7A, 0x00, 0xA0, 0x42, 0x03,
    0x00, 0x07, 0x01, 0x7A, 0x00, 0xA0, 0x40, 0x02, 0x00, 0x0D, 0xC1, 0x01, 0xA5, 0x42, 0x01, 0x00,
    0x07, 0x01, 0x71, 0x00, 0xA0, 0x40, 0x02, 0x00, 0x17, 0x01, 0x7A, 0x00, 0xE0, 0xC0, 0x02, 0x00,
    0x0F, 0x01, 0x7A, 0x00, 0xA0, 0x40, 0x01, 0x00, 0x10, 0x01, 0x7A, 0x00, 0xA0, 0x40, 0x02, 0x00,
    0x11, 0x01, 0x7A, 0x00, 0xA0, 0x40, 0x02, 0x00, 0x13, 0xC1, 0x01, 0xD4, 0x42, 0x01, 0x00, 0x1A,
    0x01, 0x71, 0x00, 0xA0, 0x40, 0x02, 0x00, 0x19, 0x01, 0x75, 0x71, 0x00, 0xA0, 0x40, 0x00, 0x00,
    0x00, 0x40, 0x6B, 0x01, 0xE9, 0x6D, 0x01, 0xEE, 0x00, 0xA0, 0x40, 0x01, 0x00, 0x08, 0xA0, 0x40,
    0x01, 0x00, 0x08, 0x40, 0x6B, 0x01, 0xFB, 0x6D, 0x02, 0x00, 0x00, 0xA0, 0x40, 0x01, 0x00, 0x1B,
    0xA0, 0x40, 0x01, 0x00, 0x1B, 0xA0, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x00, 0xA0,
    0x00, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x00
};

static const uint8_t sequence_transform_completions_data[COMPLETIONS_SIZE] PROGMEM = {
    0x27, 0x72, 0x65, 0x20, 0x27, 0x74, 0x20, 0x69, 0x7A, 0x65, 0x75, 0x65, 0x65, 0x69, 0x67, 0x69,
    0x6C, 0x69, 0x6D, 0x69, 0x6E, 0x75, 0x61, 0x75, 0x69, 0x75, 0x6F, 0x79
};
