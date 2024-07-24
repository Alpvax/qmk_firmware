#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
// #include "transactions.h"
#include "version.h"

#include "shavian_fontmap.h"

#define NUM_SPC LT(_NUMPAD, KC_SPC)
#define SFT_RET RSFT_T(KC_ENT)
#define MO_RSE MO(_RAISE)
#define MO_LWR MO(_LOWER)
#define MO_EXT MO(_EXTEND)

#define SFT_QOT LSFT(KC_QUOT)
#define S_NUBS LSFT(KC_NUBS)
#define S_HASH LSFT(KC_NUHS)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK_DH,
    _QWERTY,
    _GAME,
    _SHAW_1,
    // _SHAW_2,
    _NUMPAD,
    _RAISE,
    _LOWER,
    _EXTEND,
    _ADJ,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_GAME,
    KC_SHAW,
    KC_NUMPAD,
    KC_PRVW,
    KC_NXTW,
    KC_LSTT,
    KC_LEND,
    KC_DLWD,
    KC_SRCH
};

enum shavian_keys {
    SHAW_PEEP,      // U+10450:𐑐
    SHAW_TOT,       // U+10451:𐑑
    SHAW_KICK,      // U+10452:𐑒
    SHAW_FEE,       // U+10453:𐑓
    SHAW_THIGH,     // U+10454:𐑔
    SHAW_SO,        // U+10455:𐑕
    SHAW_SURE,      // U+10456:𐑖
    SHAW_CHURCH,    // U+10457:𐑗
    SHAW_YEA,       // U+10458:𐑘
    SHAW_HUNG,      // U+10459:𐑙
    SHAW_BIB,       // U+1045A:𐑚
    SHAW_DEAD,      // U+1045B:𐑛
    SHAW_GAG,       // U+1045C:𐑜
    SHAW_VOW,       // U+1045D:𐑝
    SHAW_THEY,      // U+1045E:𐑞
    SHAW_ZOO,       // U+1045F:𐑟

    SHAW_MEASURE,   // U+10460:𐑠
    SHAW_JUDGE,     // U+10461:𐑡
    SHAW_WOE,       // U+10462:𐑢
    SHAW_HAHA,     // U+10463:𐑣
    SHAW_LOLL,      // U+10464:𐑤
    SHAW_MIME,      // U+10465:𐑥
    SHAW_IF,        // U+10466:𐑦
    SHAW_EGG,       // U+10467:𐑧
    SHAW_ASH,       // U+10468:𐑨
    SHAW_ADO,       // U+10469:𐑩
    SHAW_ON,        // U+1046A:𐑪
    SHAW_WOOL,      // U+1046B:𐑫
    SHAW_OUT,       // U+1046C:𐑬
    SHAW_AH,        // U+1046D:𐑭
    SHAW_ROAR,      // U+1046E:𐑮
    SHAW_NUN,       // U+1046F:𐑯

    SHAW_EAT,       // U+10470:𐑰
    SHAW_AGE,       // U+10471:𐑱
    SHAW_ICE,       // U+10472:𐑲
    SHAW_UP,        // U+10473:𐑳
    SHAW_OAK,       // U+10474:𐑴
    SHAW_OOZE,      // U+10475:𐑵
    SHAW_OIL,       // U+10476:𐑶
    SHAW_AWE,       // U+10477:𐑷
    SHAW_ARE,       // U+10478:𐑸
    SHAW_OR,        // U+10479:𐑹
    SHAW_AIR,       // U+1047A:𐑺
    SHAW_ERR,       // U+1047B:𐑻
    SHAW_ARRAY,     // U+1047C:𐑼
    SHAW_EAR,       // U+1047D:𐑽
    SHAW_IAN,       // U+1047E:𐑾
    SHAW_YEW,       // U+1047F:𐑿
};

const uint32_t PROGMEM unicode_map[] = {
    [SHAW_PEEP] = 0x10450, // 𐑐
    [SHAW_TOT] = 0x10451, // 𐑑
    [SHAW_KICK] = 0x10452, // 𐑒
    [SHAW_FEE] = 0x10453, // 𐑓
    [SHAW_THIGH] = 0x10454, // 𐑔
    [SHAW_SO] = 0x10455, // 𐑕
    [SHAW_SURE] = 0x10456, // 𐑖
    [SHAW_CHURCH] = 0x10457, // 𐑗
    [SHAW_YEA] = 0x10458, // 𐑘
    [SHAW_HUNG] = 0x10459, // 𐑙
    [SHAW_BIB] = 0x1045A, // 𐑚
    [SHAW_DEAD] = 0x1045B, // 𐑛
    [SHAW_GAG] = 0x1045C, // 𐑜
    [SHAW_VOW] = 0x1045D, // 𐑝
    [SHAW_THEY] = 0x1045E, // 𐑞
    [SHAW_ZOO] = 0x1045F, // 𐑟
    [SHAW_MEASURE] = 0x10460, // 𐑠
    [SHAW_JUDGE] = 0x10461, // 𐑡
    [SHAW_WOE] = 0x10462, // 𐑢
    [SHAW_HAHA] = 0x10463, // 𐑣
    [SHAW_LOLL] = 0x10464, // 𐑤
    [SHAW_MIME] = 0x10465, // 𐑥
    [SHAW_IF] = 0x10466, // 𐑦
    [SHAW_EGG] = 0x10467, // 𐑧
    [SHAW_ASH] = 0x10468, // 𐑨
    [SHAW_ADO] = 0x10469, // 𐑩
    [SHAW_ON] = 0x1046A, // 𐑪
    [SHAW_WOOL] = 0x1046B, // 𐑫
    [SHAW_OUT] = 0x1046C, // 𐑬
    [SHAW_AH] = 0x1046D, // 𐑭
    [SHAW_ROAR] = 0x1046E, // 𐑮
    [SHAW_NUN] = 0x1046F, // 𐑯
    [SHAW_EAT] = 0x10470, // 𐑰
    [SHAW_AGE] = 0x10471, // 𐑱
    [SHAW_ICE] = 0x10472, // 𐑲
    [SHAW_UP] = 0x10473, // 𐑳
    [SHAW_OAK] = 0x10474, // 𐑴
    [SHAW_OOZE] = 0x10475, // 𐑵
    [SHAW_OIL] = 0x10476, // 𐑶
    [SHAW_AWE] = 0x10477, // 𐑷
    [SHAW_ARE] = 0x10478, // 𐑸
    [SHAW_OR] = 0x10479, // 𐑹
    [SHAW_AIR] = 0x1047A, // 𐑺
    [SHAW_ERR] = 0x1047B, // 𐑻
    [SHAW_ARRAY] = 0x1047C, // 𐑼
    [SHAW_EAR] = 0x1047D, // 𐑽
    [SHAW_IAN] = 0x1047E, // 𐑾
    [SHAW_YEW] = 0x1047F, // 𐑿
};

/*
 * Layer template
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   | Delete|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  ESC  |   Q   |   W   |   F   |   P   |   B   |                    |   J   |   L   |   U   |   Y   |   ;   |  Bspc |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  TAB  |   A   |   R   |   S   |   T   |   G   |                    |   M   |   N   |   E   |   I   |   O   |   '   |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * | LShift|   Z   |   X   |   C   |   D   |   V   |  N/F  |    |  N/F  |   K   |   H   |   ,   |   .   |   /   | RShift|
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCTRL |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
// [_KEY] = LAYOUT(
//     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,XXXXXXX,     XXXXXXX,_______,_______,_______,_______,_______,_______,
//                     _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______
// ),


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK_DH
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   | Delete|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  ESC  |   Q   |   W   |   F   |   P   |   B   |                    |   J   |   L   |   U   |   Y   |   ;   |  Bspc |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  TAB  |   A   |   R   |   S   |   T   |   G   |                    |   M   |   N   |   E   |   I   |   O   |   '   |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * | LShift|   Z   |   X   |   C   |   D   |   V   |  N/F  |    |  N/F  |   K   |   H   |   ,   |   .   |   /   | RShift|
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCtrl |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
[_COLEMAK_DH] = LAYOUT(
     KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                        KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_DEL,
     KC_ESC,   KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                        KC_J,   KC_L,   KC_U,   KC_Y,KC_SCLN,KC_BSPC,
     KC_TAB,   KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                        KC_M,   KC_N,   KC_E,   KC_I,   KC_O,KC_QUOT,
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,XXXXXXX,     XXXXXXX,   KC_K,   KC_H,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
                    KC_SRCH,KC_LALT,KC_LCTL, MO_LWR,NUM_SPC,     SFT_RET, MO_RSE,KC_RCTL,KC_RALT,KC_RGUI
),
/*
 * QWERTY
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   | Delete|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  ESC  |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |  Bspc |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  Tab  |   A   |   S   |   D   |   F   |   G   |                    |   H   |   J   |   K   |   L   |   ;   |   '   |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * | LShift|   Z   |   X   |   C   |   V   |   B   |  N/F  |    |  N/F  |   N   |   M   |   ,   |   .   |   /   | RShift|
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCtrl |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
[_QWERTY] = LAYOUT(
     KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                        KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_DEL,
     KC_ESC,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSPC,
     KC_TAB,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                        KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,XXXXXXX,     XXXXXXX,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
                    KC_SRCH,KC_LALT,KC_LCTL, MO_LWR,NUM_SPC,     SFT_RET, MO_RSE,KC_RCTL,KC_RALT,KC_RGUI
),
/*
 * GAME
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   | Delete|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  ESC  |   T   |   Q   |   W   |   E   |   R   |                    |   Y   |   U   |   I   |   O   |   P   |  Bspc |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  Tab  | LShift|   A   |   S   |   D   |   F   |                    |   H   |   J   |   K   |   L   |   ;   |   '   |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * |   Z   | LCtrl |   X   |   C   |   V   |   B   |  N/F  |    |  N/F  |   N   |   M   |   ,   |   .   |   /   | RShift|
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 | LOWER |  LAlt |   G   |/ NUBS/  Space |    |  Enter \RAISE\| RCtrl |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
[_GAME] = LAYOUT(
   MO(_ADJ),   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                        KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_DEL,
     KC_ESC,   KC_T,   KC_Q,   KC_W,   KC_E,   KC_R,                        KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSPC,
     KC_TAB,KC_LSFT,   KC_A,   KC_S,   KC_D,   KC_F,                        KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,
       KC_Z,KC_LCTL,   KC_X,   KC_C,   KC_V,   KC_B,XXXXXXX,     XXXXXXX,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
                     MO_LWR,KC_LALT,   KC_G,KC_NUBS, KC_SPC,     SFT_RET, MO_RSE,KC_RCTL,KC_RALT,KC_RGUI
),
/*
 * Shavian layer 1
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   | Delete|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  ESC  |       |   𐑘 𐑢  |  𐑓 𐑝  |  𐑐 𐑚  |  𐑖  𐑠  |                    |  𐑭 𐑸  |  𐑫 𐑵  |  𐑳 𐑿  |      |   ;   |  Bspc |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  TAB  |  𐑨 𐑲  |   𐑮 𐑤  |  𐑕 𐑟  |  𐑑 𐑛  |  𐑗 𐑡  |                    |  𐑧 𐑱  |  𐑥 𐑯  |  𐑩 𐑼  |  𐑦 𐑰  |  𐑪 𐑴  |   '   |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * | LShift|  𐑷 𐑹  |  𐑻 𐑺  |  𐑒 𐑜  |  𐑔 𐑞  |  𐑾 𐑽 |  N/F  |    |  N/F  |  𐑶 𐑬  |  𐑣 𐑙  |   ,   |   .   |   /   | RShift|
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCTRL |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
[_SHAW_1] = LAYOUT(
    /*TopRow*/ _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
    /*Row1:L*/ _______,_______,UP(SHAW_WOE, SHAW_YEW),UP(SHAW_FEE, SHAW_VOW),UP(SHAW_PEEP, SHAW_BIB),UP(SHAW_SURE, SHAW_MEASURE),
    /*Row1:R*/ UP(SHAW_AH,SHAW_ARE),UP(SHAW_WOOL,SHAW_OOZE),UP(SHAW_UP,SHAW_YEW),_______,_______,_______,
    /*HomeRow:L*/ _______,UP(SHAW_ASH, SHAW_ICE),UP(SHAW_ROAR, SHAW_LOLL),UP(SHAW_SO,SHAW_ZOO),UP(SHAW_TOT,SHAW_DEAD),UP(SHAW_CHURCH,SHAW_JUDGE),
    /*HomeRow:R*/ UP(SHAW_EGG,SHAW_AGE),UP(SHAW_NUN,SHAW_MIME),UP(SHAW_ADO,SHAW_ARRAY),UP(SHAW_IF,SHAW_EAT),UP(SHAW_ON,SHAW_OAK),_______,
    /*Row3:L*/ _______,UP(SHAW_AWE,SHAW_OR),UP(SHAW_ERR,SHAW_AIR),UP(SHAW_KICK,SHAW_GAG),UP(SHAW_THIGH,SHAW_THEY),UP(SHAW_IAN,SHAW_EAR),XXXXXXX,
    /*Row3:R*/ XXXXXXX,UP(SHAW_OIL,SHAW_OUT),UP(SHAW_HAHA,SHAW_HUNG),_______,_______,_______,_______,
    /*ModRow*/                KC_SRCH,KC_LALT,KC_LCTL, MO_LWR,NUM_SPC,     SFT_RET, MO_RSE,KC_RCTL,KC_RALT,KC_RGUI
),
/*
 * Shavian layer 2
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   | Delete|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  ESC  |   Q   |   W   |   F   |   P   |   B   |                    |   J   |   L   |   U   |   Y   |   ;   |  Bspc |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  TAB  |   A   |   R   |   S   |   T   |   G   |                    |   M   |   N   |   E   |   I   |   O   |   '   |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * | LShift|   Z   |   X   |   C   |   D   |   V   |  N/F  |    |  N/F  |   K   |   H   |   ,   |   .   |   /   | RShift|
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCTRL |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
// [_SHAW_2] = LAYOUT(
//     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,                     _______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,     _______,_______,_______,_______,_______,_______,_______,
//                     _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______
// ),
/* NUMPAD
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |       |       |       |       |       |       |                    |       |   D   |   E   |   F   |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |   ,   |  S(C) |  S(B) |  S(A) |   @   |                    |   C   |  Num7 |  Num8 |  Num9 |  KP_* |  KP_/ |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |  KP_/ |   .   |  KP_- |  KP_+ |   X   |                    |   B   |  Num4 |  Num5 |  Num6 |   .   |  KP_- |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * |       |  KP_* |  S(F) |  S(E) |  S(D) |   :   |  N/F  |    |  N/F  |   A   |  Num1 |  Num2 |  Num3 |   ,   |  KP_+ |
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |       |       |       |/     /        |    |        \     \|  Num0 |       |       |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
[_NUMPAD] = LAYOUT(
    _______,_______,_______,_______,_______,_______,                     _______,   KC_D,   KC_E,   KC_F,_______,_______,
    _______,KC_COMM,S(KC_C),S(KC_B),S(KC_A),SFT_QOT,                        KC_C,KC_KP_7,KC_KP_8,KC_KP_9,KC_PAST,KC_PSLS,
    _______,KC_PSLS, KC_DOT,KC_PMNS,KC_PPLS,   KC_X,                        KC_B,KC_KP_4,KC_KP_5,KC_KP_6, KC_DOT,KC_PMNS,
    _______,KC_PAST,S(KC_F),S(KC_E),S(KC_D),KC_COLN,_______,     _______,   KC_A,KC_KP_1,KC_KP_2,KC_KP_3,KC_COMM,KC_PPLS,
                    _______,_______,_______,_______,_______,     _______,_______,KC_KP_0, _______, _______
),
/* RAISE
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |       |       |       |       |       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  Esc  |  Ins  |  Pscr |  Menu |       |       |                    |  PgUp | LStrt |  LEnd |  PgDn |BspcWrd|  Bspc |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  Tab  |  LAlt | LCtrl | LShift|       |  Caps |                    |  Left |  Down |   Up  | Right |  Bspc |  Del  |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * | Shift |  Undo |  Cut  |  Copy | Paste |       |  N/F  |    |  N/F  |       |  PWrd |  NWrd |       |       | Shift |
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCtrl |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
[_RAISE] = LAYOUT(
   _______,_______,_______,_______,_______,_______,                       _______,_______,_______,_______,_______,_______,
   _______, KC_INS,KC_PSCR, KC_APP,XXXXXXX,XXXXXXX,                       KC_PGUP,KC_LSTT,KC_LEND,KC_PGDN,KC_DLWD,KC_BSPC,
   _______,KC_LALT,KC_LCTL,KC_LSFT,XXXXXXX,KC_CAPS,                       KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,KC_BSPC, KC_DEL,
   _______,KC_UNDO, KC_CUT,KC_COPY,KC_PSTE,KC_PSTE,_______,       _______,XXXXXXX,KC_PRVW,KC_NXTW,XXXXXXX,XXXXXXX,_______,
                   _______,_______,_______,_______,_______,       _______,_______,_______,_______,_______
),
/* LOWER
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |       |   F1  |   F2  |   F3  |   F4  |   F5  |                    |   F6  |   F7  |   F8  |   F9  |  F10  |  F11  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |  F12  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  Tab  |   !   |   "   |   £   |   $   |   %   |                    |   ^   |   &   |   *   |   (   |   )   |   #   |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * | Extend|   =   |   +   |   -   |   {   |   }   |  N/F  |    |  N/F  |   [   |   ]   |   ;   |   :   |   \   | Extend|
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCtrl |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
[_LOWER] = LAYOUT(
   _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,
    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,   KC_7,   KC_8,   KC_9,   KC_0, KC_F12,
   _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_NUHS,
    MO_EXT,  KC_EQL,KC_PLUS,KC_MINS,KC_LCBR,KC_RCBR,_______,    _______,KC_LBRC,KC_RBRC,KC_SCLN,KC_COLN,KC_NUBS, MO_EXT,
                    _______,_______,_______,_______,_______,    _______,_______,_______,_______,_______
),
/* EXTEND
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |       |  F13  |  F14  |  F15  |  F16  |  F17  |                    |  F18  |  F19  |  F20  |  F21  |  F22  |  F23  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |   `   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |  F24  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |  Tab  |   !   |   "   |   £   |   $   |   %   |                    |   ^   |   &   |   *   |   (   |   )   |   ~   |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * | Extend|   \   |   +   |   _   |   {   |   }   |  N/F  |    |  N/F  |   [   |   ]   |   ;   |   :   |   |   | Extend|
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCtrl |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
[_EXTEND] = LAYOUT(
   _______, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17,                       KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23,
   _______,_______,_______,_______,_______,_______,                      _______,_______,_______,_______,_______, KC_F24,
   _______,_______,_______,_______,_______,_______,                      _______,_______,_______,_______,_______, S_HASH,
   _______,KC_NUBS,_______,KC_UNDS,_______,_______,_______,      _______,_______,_______,_______,_______, S_NUBS,_______,
                   _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______
),
/* ADJUST
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |       |       |       |       |       |       |                    |dyn tap| dt_up | dt_dn |UC_PREV|UC_NEXT|MACWIN|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |QK_BOOT| Numpad| QWERTY|Colemak|  GAME |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       |       |Shavian|       |       |                    |       | VOLDN |  MUTE | VOLUP |       |       |
 * |-------+-------+-------+-------+-------+-------|-------.    ,-------|-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  N/F  |    |  N/F  |       |  PREV |  PLAY |  NEXT |       |       |
 * `---------------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+---------------'
 *                 |  LGUI |  LAlt | LCTRL |/LOWER/  Space |    |  Enter \RAISE\| RCtrl |  RAlt |  RGUI |
 *                 `-----------------------'-----'---------'     `--------'-----'-----------------------'
 */
  [_ADJ] = LAYOUT(
   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                     DT_PRNT,DT_UP  ,DT_DOWN,UC_PREV,UC_NEXT,CG_TOGG,
   QK_BOOT,KC_NUMPAD,KC_QWERTY,KC_COLEMAK,KC_GAME,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
   XXXXXXX,XXXXXXX,XXXXXXX,KC_SHAW,XXXXXXX,XXXXXXX,                     XXXXXXX,KC_VOLD,KC_MUTE,KC_VOLU,XXXXXXX,XXXXXXX,
   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,     XXXXXXX,XXXXXXX,KC_MPRV,KC_MPLY,KC_MNXT,XXXXXXX,XXXXXXX,
                   _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______
  )
};

#ifdef OLED_ENABLE

// sync transport
// typedef struct _sync_ver_t {
//     char ver[17];
// } sync_ver_t;

// sync_ver_t master_version;

// void user_sync_ver_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
//     const sync_ver_t* m2s = (const sync_ver_t*)in_data;
//     // get the last char typed on left side and update the right side
//     strcpy(master_version.ver, m2s->ver);
// }

// void keyboard_post_init_user(void) {
//     // callback for tranport sync data
//     transaction_register_rpc(USER_SYNC_VER, user_sync_ver_handler);
//     if (is_keyboard_master()) {
//         strcpy(master_version.ver, BUILD_VERSION);
//         transaction_rpc_send(USER_SYNC_VER, sizeof(master_version), &master_version);
//     }
// }

static void render_logo(void) {
    static const char PROGMEM qmk_logo_compact[] = {
        0x20,0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
        0x20,0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0x8B,0x8C,0x8D,0x8E,0x8F,0x20,
        0x20,0xC0,0xC1,0xC2,0xC3,0x20,0xC5,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
        0
    };

    oled_write_P(qmk_logo_compact, false);
    oled_write_P(PSTR(" "), false);
    oled_write(QMK_BUILDDATE, false);
}

static void print_status_common(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwrty"), false);
            break;
        case _COLEMAK_DH:
            oled_write_P(PSTR("Colmk"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game "), false);
            break;
        case _SHAW_1:
            // oled_write_P(PSTR("Shaw "), false);
            oled_write_P(SHAVIAN_WORD, false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    // Print current layer
    oled_write_ln_P(PSTR("\n\nLAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
        case _QWERTY:
        case _SHAW_1:
            oled_write_P(PSTR("Base "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _EXTEND:
            oled_write_P(PSTR("Extnd"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpd"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_advance_page(true);
}

static void print_status_narrow(void) {
    print_status_common();
    led_t led_usb_state = host_keyboard_led_state();
    oled_advance_page(true);
    oled_advance_page(true);
    oled_advance_page(true);
    oled_advance_page(true);
    oled_advance_page(true);

    if (get_mods() & MOD_MASK_SHIFT) {
        oled_write_ln_P(PSTR("Shift"), false);
    } else {
        oled_advance_page(true);
        oled_advance_page(true);
    }
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

static void print_status_narrow_ADJ(void) {
    print_status_common();
    // Print current mode
    oled_write_P(PSTR("MODE:"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR(" MAC"), false);
    } else {
        oled_write_ln_P(PSTR(" WIN"), false);
    }
    switch (get_unicode_input_mode()) {
        case UNICODE_MODE_MACOS:	    // macOS input
            oled_write_P(PSTR(" MAC"), false);
            break;
        case UNICODE_MODE_LINUX:	    // Linux input
            oled_write_P(PSTR(" Lin"), false);
            break;
        case UNICODE_MODE_WINDOWS:	// Windows input
            oled_write_P(PSTR(" Win"), false);
            break;
        case UNICODE_MODE_WINCOMPOSE:// Windows input using WinCompose
            oled_write_P(PSTR(" WinC"), false);
            break;
        // case UNICODE_MODE_EMACS:	    // emacs (C-x-8 RET) input
        // case UNICODE_MODE_BSD:	    // BSD input (not implemented)
        default:
            oled_advance_page(true);
    }
    oled_write_P(PSTR("\nBUILD"), false);
    char s[6] = {0,0,0,0,0,0};
    strncpy(s, QMK_BUILDDATE, 5);
    oled_write(s, false);
    strncpy(s, QMK_BUILDDATE + 5, 5);
    oled_write(s, false);
    strncpy(s, QMK_BUILDDATE + 11, 5);
    oled_write(s, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (get_highest_layer(layer_state) == _ADJ) {
            print_status_narrow_ADJ();
        } else {
            print_status_narrow();
        }
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(default_layer_state) != _GAME || get_highest_layer(layer_state) == _ADJ) {
        state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJ);
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t srch_timer;
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
            }
            return false;
        case KC_SHAW:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_SHAW_1);
            }
            return false;
        case KC_NUMPAD:
            if (record->event.pressed) {
                layer_invert(_NUMPAD);
            }
            return false;
        case KC_PRVW:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_LEFT);
                    unregister_mods(mod_config(MOD_LALT));
                } else {
                    unregister_code(KC_LEFT);
                    unregister_mods(mod_config(MOD_LCTL));
                }
            }
            break;
        case KC_NXTW:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_RIGHT);
                    unregister_mods(mod_config(MOD_LALT));
                } else {
                    unregister_code(KC_RIGHT);
                    unregister_mods(mod_config(MOD_LCTL));
                }
            }
            break;
        case KC_LSTT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_LEFT);
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_code(KC_RIGHT);
                    unregister_mods(mod_config(MOD_LCTL));
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLWD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_code(KC_BSPC);
                unregister_mods(mod_config(MOD_LCTL));
            }
            break;
        case KC_SRCH:
            if (record->event.pressed) {
                srch_timer = timer_read();
                register_mods(mod_config(MOD_LGUI));
            } else {
                if (timer_elapsed(srch_timer) < TAPPING_TERM) {
                    register_code(KC_F23);
                }
                unregister_mods(mod_config(MOD_LGUI));
            }
            break;
            // return false;        // Return false to ignore further processing of key
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_code(KC_C);
                unregister_mods(mod_config(MOD_LCTL));
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_code(KC_V);
                unregister_mods(mod_config(MOD_LCTL));
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_code(KC_X);
                unregister_mods(mod_config(MOD_LCTL));
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_code(KC_Z);
                unregister_mods(mod_config(MOD_LCTL));
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
