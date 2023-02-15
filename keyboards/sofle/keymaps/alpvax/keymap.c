#include QMK_KEYBOARD_H


#define MASTER_RIGHT

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK_DH,
    _QWERTY,
    _GAME,
    _LOWER,
    _RAISE,
    _EXTEND,
    _NUMPAD,
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
    KC_DLIN
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
 *               `--------------------'-----'--------'      `------'-----'--------------------'
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
 *               `--------------------'-----'--------'      `------'-----'--------------------'
 */
[_COLEMAK_DH] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, XXXXXXX,      XXXXXXX,KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,MO(_NUMPAD),KC_LCTL,MO(_LOWER), KC_SPC,        KC_ENT,  MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
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
 *               `--------------------'-----'--------'      `------'-----'--------------------'
 */
[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,MO(_NUMPAD),KC_LCTL, MO(_LOWER), KC_SPC,      KC_ENT,  MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
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
 *               `--------------------'-----'--------'      `------'-----'--------------------'
 */
[_GAME] = LAYOUT(
  MO(_ADJUST),KC_1, KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_T,   KC_Q,    KC_W,    KC_E,    KC_R,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_TAB,   KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_Z,  KC_LCTL,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 MO(_LOWER),KC_LGUI,KC_LALT,KC_NUBS, KC_SPC,      KC_ENT,  MO(_RAISE), KC_RCTL, KC_RALT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * | Shift|  =   |  +   |  -   |   {  |   }  |  N/F  |    |  N/F  |   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-------------+------+------+------+------+--------    --------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'      `------'-----'--------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_PLUS, KC_MINS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    | PgUp | LStrt| LEnd | PgDn | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |                    | Left | Down |  Up  | Right| Bspc |  Del |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |  N/F  |    |  N/F  |      | PWrd | NWrd |      |      | Shift|
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'      `------'-----'--------------------'
 */
[_RAISE] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______, KC_INS,KC_PSCR, KC_APP,XXXXXXX,XXXXXXX,                        KC_PGUP, KC_LSTT, KC_LEND, KC_PGDN, KC_DLIN, KC_BSPC,
  _______,KC_LALT,KC_LCTL,KC_LSFT,XXXXXXX,KC_CAPS,                       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSPC,  KC_DEL,
  _______,KC_UNDO, KC_CUT,KC_COPY,KC_PASTE,KC_PASTE,_______,       _______,  XXXXXXX, KC_PRVW, KC_NXTW, XXXXXXX,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* EXTEND
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |                    |      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |  N/F  |    |  N/F  |      | LStr |      | LEnd |      | Shift|
 * `-------------+------+------+------+------+-------|    |-------+------+------+------+------+-------------'
 *               | LGUI | LAlt | LCTR |/LOWER/ Space |    | Enter \RAISE\| RCTR | RAlt | RGUI |
 *               `--------------------'-----'--------'      `------'-----'--------------------'
 */
[_EXTEND] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVW,   KC_UP, KC_NXTW,KC_DLIN, KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
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
 *               `--------------------'-----'--------'      `------'-----'--------------------'
 */
[_NUMPAD] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______ ,                          _______ , KC_D    , KC_E    , KC_F    , _______ , _______,
  _______, _______ , _______ , _______ , _______ , _______ ,                          KC_C    , KC_KP_7 , KC_KP_8 , KC_KP_9 , KC_PAST , KC_PSLS,
  _______, _______ , _______ , _______ , _______ , _______ ,                          KC_B    , KC_KP_4 , KC_KP_5 , KC_KP_6 , KC_DOT  , KC_PMNS,
  _______, _______ , _______ , _______ , _______ , _______ , _______,       _______ , KC_A    , KC_KP_1 , KC_KP_2 , KC_KP_3 , KC_COMMA, KC_PPLS,
                     _______ , _______ , _______ , _______ , _______,       _______ , _______ , KC_KP_0 , _______ , _______
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
 *               `--------------------'-----'--------'      `------'-----'--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAK,KC_GAME,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR(""), false);
    oled_write_P(PSTR("Build"), false);
    oled_write_ln_P(PSTR("02-15"), false);
    oled_write_P(PSTR(""), false);
    // oled_write_ln_P(PSTR("MODE"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK_DH:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK_DH:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
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
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        case KC_DLIN:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_code(KC_BSPC);
                unregister_mods(mod_config(MOD_LCTL));
            }
            break;
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
