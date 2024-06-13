// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// This was file generated on 2024-06-13 01:09:38.
// Do not edit this file directly!

#pragma once

#define SEQUENCE_TRANSFORM_GENERATOR_VERSION_3_2

#define TRIECODE_SEQUENCE_TOKEN_0 0x0080
#define TRIECODE_SEQUENCE_METACHAR_0 0x00A0
#define TRIECODE_SEQUENCE_REF_TOKEN_0 0x0080
#define SEQUENCE_MIN_LENGTH 2 // "a👆"
#define SEQUENCE_MAX_LENGTH 5 // "dont👆"
#define TRANSFORM_MAX_LENGTH 6 // "‸I'll⎵"
#define COMPLETION_MAX_LENGTH 5
#define MAX_BACKSPACES 2
#define SEQUENCE_TRIE_SIZE 582
#define COMPLETIONS_SIZE 50
#define SEQUENCE_TOKEN_COUNT 4
#define SEQUENCE_METACHAR_COUNT 8
#define SEQUENCE_REF_TOKEN_COUNT 8

static const char st_seq_token_ascii_chars[] = { '*', '@', '#', '&' };
#ifdef ST_TESTER
static const char *st_seq_tokens[] = { "👆", "✪", "★", "👍" };
static const char *st_seq_metachars[] = { "∆", "∇", "∂", "‼", "‥", "•", "‸", "∀" };
static const char *st_trans_seq_ref_tokens[] = { "◯", "⑴", "⑵", "⑶", "⑷", "⑸", "⑹", "⑺" };
static const char *st_space_token = "⎵";
#endif

// Sequence Transformation dictionary with longest match semantics
// Dictionary (59 entries):
//    a👆    -> ao
//    o👆    -> oa
//    u👆    -> ue
//    e👆    -> eu
//    ‸✪    -> ‸f
//    ‸👆    -> ‸w
//    i👆    -> ike
//    c👆    -> ck
//    p👆    -> py
//    x👆    -> xp
//    h👆    -> hy
//    y👆    -> yp
//    w👆    -> ws
//    s👆    -> sw
//    z👆    -> zs
//    v👆    -> vs
//    r👆    -> rl
//    l👆    -> lr
//    b👆    -> bl
//    n👆    -> nb
//    t👆    -> tw
//    g👆    -> gs
//    qe    -> que
//    qa    -> qua
//    qi    -> qui
//    qo    -> quo
//    ‸i👆   -> ‸I⎵
//    ‸ie   -> ‸if
//    ‸if   -> ‸ie
//    if👆   -> ife
//    i👆👆   -> iking
//    ‸e👆   -> ‸key
//    ‸k👆   -> ‸ki
//    ck👆   -> cky
//    ∇k👆   -> ∇ky
//    ab👆   -> able
//    quu   -> qu
//    qaa   -> qa
//    qee   -> qe
//    qii   -> qi
//    qoo   -> qo
//    ‸ee👆  -> ‸eu
//    ‸il👆  -> ‸I'll⎵
//    ‸iv👆  -> ‸I've⎵
//    ‸im👆  -> ‸I'm⎵
//    ‸ie👆  -> ‸ie
//    iff👆  -> ifa
//    ck👆l  -> ckly
//    ‸oh👆  -> ‸okay
//    ∇k👆g  -> ∇king
//    ∇k👆d  -> ∇kind
//    ab👆y  -> ably
//    ab👆i  -> abli
//    dont👆 -> don't
//    wont👆 -> won't
//    cant👆 -> can't
//    ∇dnt👆 -> ∇dn't
//    ∇lds👆 -> ∇ld've
//    ‸its👆 -> ‸it's⎵

static const uint8_t sequence_transform_trie[SEQUENCE_TRIE_SIZE] PROGMEM = {
    0x40, 0x61, 0x00, 0x2C, 0x64, 0x00, 0x3B, 0x65, 0x00, 0x42, 0x66, 0x00, 0x5E, 0x67, 0x00, 0x67,
    0x69, 0x00, 0x6E, 0x6C, 0x00, 0x83, 0x6F, 0x00, 0x8A, 0x75, 0x00, 0x99, 0x79, 0x00, 0xA2, 0x80,
    0x00, 0xA9, 0x81, 0x02, 0x2F, 0x82, 0x02, 0x3C, 0x83, 0x02, 0x41, 0x00, 0xC1, 0x00, 0x37, 0x42,
    0x01, 0x00, 0x18, 0x01, 0x71, 0x00, 0xA0, 0x40, 0x02, 0x00, 0x25, 0x81, 0x01, 0x7B, 0x41, 0x03,
    0x00, 0x11, 0xC1, 0x00, 0x5A, 0x42, 0x01, 0x00, 0x08, 0x40, 0x69, 0x00, 0x51, 0x71, 0x00, 0x59,
    0x00, 0x01, 0xA6, 0x00, 0xA0, 0x40, 0x01, 0x00, 0x2E, 0xA0, 0x40, 0x02, 0x00, 0x27, 0x01, 0x69,
    0xA6, 0x00, 0xA0, 0x40, 0x01, 0x00, 0x08, 0x81, 0x01, 0x7B, 0x41, 0x03, 0x00, 0x14, 0xC2, 0x00,
    0x7F, 0x42, 0x01, 0x00, 0x11, 0x01, 0x12, 0x41, 0x01, 0x00, 0x11, 0x01, 0x71, 0x00, 0xA0, 0x40,
    0x02, 0x00, 0x29, 0x81, 0x01, 0x76, 0x41, 0x02, 0x00, 0x23, 0xC1, 0x00, 0x95, 0x42, 0x01, 0x00,
    0x2C, 0x01, 0x71, 0x00, 0xA0, 0x40, 0x02, 0x00, 0x2B, 0x01, 0x75, 0x71, 0x00, 0xA0, 0x40, 0x00,
    0x00, 0x00, 0x81, 0x01, 0x12, 0x41, 0x01, 0x00, 0x19, 0xE2, 0x80, 0x00, 0x00, 0x00, 0x01, 0x5E,
    0x41, 0x03, 0x00, 0x14, 0x00, 0x55, 0x41, 0x01, 0x00, 0x08, 0x60, 0x61, 0x01, 0x04, 0x62, 0x01,
    0x09, 0x63, 0x01, 0x16, 0x65, 0x01, 0x1B, 0x66, 0x01, 0x35, 0x67, 0x01, 0x4A, 0x68, 0x01, 0x4F,
    0x69, 0x01, 0x5D, 0x6B, 0x01, 0x6A, 0x6C, 0x01, 0x84, 0x6D, 0x01, 0x92, 0x6E, 0x01, 0x9B, 0x6F,
    0x01, 0xA0, 0x70, 0x01, 0xA5, 0x72, 0x01, 0xAA, 0x73, 0x01, 0xAF, 0x74, 0x01, 0xCE, 0x75, 0x02,
    0x03, 0x76, 0x02, 0x08, 0x77, 0x02, 0x16, 0x78, 0x02, 0x1B, 0x79, 0x02, 0x20, 0x7A, 0x02, 0x25,
    0xA6, 0x02, 0x2A, 0x00, 0xA0, 0x40, 0x01, 0x00, 0x2C, 0xE0, 0xC0, 0x01, 0x00, 0x02, 0x01, 0x61,
    0x00, 0xA0, 0x40, 0x02, 0x00, 0x21, 0xA0, 0x40, 0x01, 0x00, 0x17, 0xE0, 0xC0, 0x01, 0x00, 0x25,
    0x60, 0x65, 0x01, 0x28, 0xA6, 0x01, 0x30, 0x00, 0x01, 0xA6, 0x00, 0xA0, 0x41, 0x01, 0x00, 0x25,
    0xA0, 0x41, 0x03, 0x00, 0x1A, 0x40, 0x66, 0x01, 0x3D, 0x69, 0x01, 0x45, 0x00, 0x01, 0x69, 0x00,
    0xA0, 0x41, 0x01, 0x00, 0x18, 0xA0, 0x40, 0x01, 0x00, 0x08, 0xA0, 0x40, 0x01, 0x00, 0x0F, 0xE0,
    0xC0, 0x01, 0x00, 0x19, 0x01, 0x6F, 0xA6, 0x00, 0xA0, 0x41, 0x03, 0x00, 0x17, 0xE0, 0xC0, 0x02,
    0x00, 0x1A, 0x01, 0xA6, 0x00, 0xA0, 0x41, 0x02, 0x00, 0x1F, 0x60, 0x63, 0x01, 0x75, 0xA1, 0x01,
    0x7A, 0xA6, 0x01, 0x7F, 0x00, 0xA0, 0x40, 0x01, 0x00, 0x19, 0xA0, 0x40, 0x01, 0x00, 0x19, 0xA0,
    0x40, 0x01, 0x00, 0x11, 0xE0, 0xC0, 0x01, 0x00, 0x30, 0x01, 0x69, 0xA6, 0x00, 0xA0, 0x42, 0x05,
    0x00, 0x00, 0x01, 0x69, 0xA6, 0x00, 0xA0, 0x42, 0x04, 0x00, 0x0A, 0xA0, 0x40, 0x01, 0x00, 0x2D,
    0xA0, 0x40, 0x01, 0x00, 0x18, 0xA0, 0x40, 0x01, 0x00, 0x19, 0xA0, 0x40, 0x01, 0x00, 0x02, 0xE0,
    0xC0, 0x01, 0x00, 0x31, 0x40, 0x64, 0x01, 0xBC, 0x74, 0x01, 0xC5, 0x00, 0x01, 0x6C, 0xA1, 0x00,
    0xA0, 0x41, 0x03, 0x00, 0x06, 0x01, 0x69, 0xA6, 0x00, 0xA0, 0x41, 0x03, 0x00, 0x0E, 0xE0, 0xC0,
    0x01, 0x00, 0x31, 0x01, 0x6E, 0x00, 0x40, 0x61, 0x01, 0xE1, 0x64, 0x01, 0xE9, 0x6F, 0x01, 0xF1,
    0x00, 0x01, 0x63, 0x00, 0xA0, 0x41, 0x02, 0x00, 0x1D, 0x01, 0xA1, 0x00, 0xA0, 0x41, 0x02, 0x00,
    0x1D, 0x40, 0x64, 0x01, 0xF9, 0x77, 0x01, 0xFE, 0x00, 0xA0, 0x41, 0x02, 0x00, 0x1D, 0xA0, 0x41,
    0x02, 0x00, 0x1D, 0xA0, 0x40, 0x01, 0x00, 0x08, 0xE0, 0xC0, 0x01, 0x00, 0x0F, 0x01, 0x69, 0xA6,
    0x00, 0xA0, 0x42, 0x05, 0x00, 0x05, 0xA0, 0x40, 0x01, 0x00, 0x0F, 0xA0, 0x40, 0x01, 0x00, 0x2F,
    0xA0, 0x40, 0x01, 0x00, 0x2F, 0xA0, 0x40, 0x01, 0x00, 0x0F, 0xA0, 0x40, 0x01, 0x00, 0x31, 0xE0,
    0x80, 0x00, 0x00, 0x00, 0x01, 0xA6, 0x00, 0xA0, 0x40, 0x01, 0x00, 0x2E, 0xA0, 0x00, 0x00, 0x00,
    0x00, 0xA0, 0x00, 0x00, 0x00, 0x00
};

static const uint8_t sequence_transform_completions_data[COMPLETIONS_SIZE] PROGMEM = {
    0x49, 0x27, 0x6C, 0x6C, 0x20, 0x49, 0x27, 0x76, 0x65, 0x20, 0x49, 0x27, 0x6D, 0x20, 0x27, 0x73,
    0x20, 0x69, 0x6E, 0x64, 0x69, 0x6E, 0x67, 0x6B, 0x61, 0x79, 0x6B, 0x65, 0x79, 0x27, 0x74, 0x49,
    0x20, 0x6C, 0x65, 0x6C, 0x79, 0x75, 0x61, 0x75, 0x65, 0x75, 0x69, 0x75, 0x6F, 0x62, 0x66, 0x70,
    0x72, 0x77
};
