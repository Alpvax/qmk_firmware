#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
// #include "transactions.h"
#include "version.h"

#define NUM_SPC LT(_NUMPAD, KC_SPC)
#define SFT_RET RSFT_T(KC_ENT)
#define MO_LWR MO(_LOWER)
#define MO_RSE MO(_RAISE)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK_DH,
    _QWERTY,
    _GAME,
    _NUMPAD,
    _RAISE,
    _LOWER,
    _EXT,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_GAME,
    KC_PRVW,
    KC_NXTW,
    KC_LSTT,
    KC_LEND,
    KC_DLWD,
    KC_SRCH
};


/*
 * Layer template
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   G  |                    |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |  N/F  |    |  N/F  |   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-------------+------+------+------+------+--------    --------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'     `-------'-----'--------------------'
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK_DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   G  |                    |   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |  N/F  |    |  N/F  |   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-------------+------+------+------+------+--------    --------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'     `-------'-----'--------------------'
 */
[_COLEMAK_DH] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX,      XXXXXXX,KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_SRCH, KC_LALT, KC_LCTL, MO_LWR, NUM_SPC,       SFT_RET,  MO_RSE, KC_RCTL, KC_RALT, KC_RGUI
),
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |  N/F  |    |  N/F  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-------------+------+------+------+------+--------    --------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'     `-------'-----'--------------------'
 */
[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_SRCH,KC_LALT,KC_LCTL, MO_LWR, NUM_SPC,      SFT_RET,  MO_RSE, KC_RCTL, KC_RALT, KC_RGUI
),
/*
 * GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   T  |   Q  |   W  |   E  |   R  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |LShift|   A  |   S  |   D  |   F  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |   Z  | LCtr |   X  |   C  |   V  |   B  |  N/F  |    |  N/F  |   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-------------+------+------+------+------+--------    --------+------+------+------+------+-------------'
 *               | LOWER| LAlt | LCTR |/ NUBS/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'     `------'-----'--------------------'
 */
[_GAME] = LAYOUT(
  MO(_ADJUST),KC_1, KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_Z,  KC_LCTL,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 MO_LWR,KC_LGUI,KC_LALT,KC_NUBS, KC_SPC,      KC_ENT,  MO_RSE, KC_RCTL, KC_RALT, KC_RGUI
),
/* NUMPAD
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |   D  |   E  |   F  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   C  | Num7 | Num8 | Num9 |   *  |   /  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   B  | Num4 | Num5 | Num6 |   .  |   -  |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  N/F  |    |  N/F  |   A  | Num1 | Num2 | Num3 |   ,  |   +  |
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+-------------'
 *               |      |      |      |/     /       |    |       \     \| Num0 |      |      |
 *               `--------------------'-----'--------'     `-------'-----'--------------------'
 */
[_NUMPAD] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______ ,                          _______ , KC_D    , KC_E    , KC_F    , _______ , _______,
  _______, _______ , _______ , _______ , _______ , _______ ,                          KC_C    , KC_KP_7 , KC_KP_8 , KC_KP_9 , KC_PAST , KC_PSLS,
  _______, _______ , _______ , _______ , _______ , _______ ,                          KC_B    , KC_KP_4 , KC_KP_5 , KC_KP_6 , KC_DOT  , KC_PMNS,
  _______, _______ , _______ , _______ , _______ , _______ , _______,       _______ , KC_A    , KC_KP_1 , KC_KP_2 , KC_KP_3 , KC_COMMA, KC_PPLS,
                     _______ , _______ , _______ , _______ , _______,       _______ , _______ , KC_KP_0 , _______ , _______
),
/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    | PgUp | LStrt| LEnd | PgDn | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |                    | Left | Down |  Up  | Right| Bspc |  Del |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |  N/F  |    |  N/F  |      | PWrd | NWrd |      |      | Shift|
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'     `------'-----'--------------------'
 */
[_RAISE] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                           _______,_______,_______,_______,_______,_______,
  _______, KC_INS,KC_PSCR, KC_APP,XXXXXXX,XXXXXXX,                        KC_PGUP, KC_LSTT, KC_LEND, KC_PGDN, KC_DLWD, KC_BSPC,
  _______,KC_LALT,KC_LCTL,KC_LSFT,XXXXXXX,KC_CAPS,                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSPC,  KC_DEL,
  _______,KC_UNDO, KC_CUT,KC_COPY,KC_PASTE,KC_PASTE,_______,       _______,  XXXXXXX, KC_PRVW, KC_NXTW, XXXXXXX,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   "  |   £  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |Extend|  =   |  +   |  -   |   {  |   }  |  N/F  |    |  N/F  |   [  |   ]  |   ;  |   :  |   \  |Extend|
 * `-------------+------+------+------+------+--------    --------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'     `------'-----'--------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  MO(_EXT), KC_EQL, KC_PLUS, KC_MINS, KC_LCBR, KC_RCBR, _______,    _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, MO(_EXT),
                       _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),
/* EXTEND
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |  F13 |  F14 |  F15 |  F16 |  F17 |                    |  F18 |  F19 |  F20 |  F21 |  F22 |  F23 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  F24 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   "  |   £  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |Extend|  \   |  +   |  _   |   {  |   }  |  N/F  |    |  N/F  |   [  |   ]  |   ;  |   :  |   \  |Extend|
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'     `-------'-----'--------------------'
 */
[_EXT] = LAYOUT(
  _______, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17,                         KC_F18,   KC_F19,  KC_F20,  KC_F21,  KC_F22 ,KC_F23,
  _______,_______,_______,_______,_______,_______,                           _______,_______,_______,_______,_______, KC_F24,
  _______,_______,_______,_______,_______,_______,                           _______,_______,_______,_______,_______,_______,
  _______,KC_NUBS,_______,KC_UNDS,_______,_______,_______,           _______,_______,_______,_______,_______,_______,_______,
                  _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |MACWIN|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * QK_BOOT|      |QWERTY| CMAK | GAME |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  N/F  |    |  N/F  |      | PREV | PLAY | NEXT |      |      |
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'     `-------'-----'--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, DT_PRNT, DT_DOWN,  DT_UP, XXXXXXX, CG_TOGG,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAK,KC_GAME,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
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
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
        ' ',0
    };

    oled_write_P(qmk_logo, false);
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
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    // Print current layer
    oled_write_ln_P(PSTR("\n\nLAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
        case _QWERTY:
            oled_write_P(PSTR("Base "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _EXT:
            oled_write_P(PSTR("Extnd"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpd"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjst"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_advance_page(true);
    oled_advance_page(true);
}

static void print_status_narrow(void) {
    print_status_common();
    led_t led_usb_state = host_keyboard_led_state();
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

static void print_status_narrow_adjust(void) {
    print_status_common();
    // Print current mode
    oled_write_P(PSTR("MODE:"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR(" MAC"), false);
    } else {
        oled_write_ln_P(PSTR(" WIN"), false);
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
        if (get_highest_layer(layer_state) == _ADJUST) {
            print_status_narrow_adjust();
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
    if (get_highest_layer(default_layer_state) != _GAME || get_highest_layer(layer_state) == _ADJUST) {
        state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
