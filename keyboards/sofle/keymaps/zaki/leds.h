#ifdef RGB_MATRIX_ENABLE
void set_key_color(uint8_t key_code, uint8_t r, uint8_t g, uint8_t b) {
    rgb_matrix_set_color(key_code, r, g, b);
}

void set_keys_color(const uint8_t keycodes[], uint8_t len, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < len; i++) {
        set_key_color(keycodes[i], r, g, b);
    }
}

#define SET_KEY_COLORS(ary, r, g, b) \
    if (sizeof(ary) > 0) set_keys_color(ary, sizeof(ary) / sizeof(uint8_t), r, g, b);

/*
Sofle rev2:
Underglow left:  {00, 01, 02, 03, 04, 05}
Underglow right: {36, 37, 38, 39, 40, 41}

        { 10, 11, 20, 21, 30, 31},             { 67, 66, 57, 56, 47, 46},
           ~   1   2   3   4   5                  6   7   8   9   0  BSP
        { 09, 12, 19, 22, 29, 32},             { 68, 65, 58, 55, 48, 45},
         ESC   Q   W   E   R   T                  Y   U   I   O   P   \
        { 08, 13, 18, 23, 28, 33},             { 69, 64, 59, 54, 49, 44},
         TAB   A   S   D   F   G                  H   J   K   L   É   Á
        { 07, 14, 17, 24, 27, 34},             { 70, 63, 60, 53, 50, 43},
         SHF   Z   X   C   V   B                  N   M   ,   .   -  SHF
        {         06, 15, 16, 25, 26},     { 62, 61, 52, 51, 42}
                 WIN ALT CTR LWR SPC        ENT RSE CTR ALT WIN


Sofle Choc:
        { 28, 21, 20, 11, 10,  0},             { 29, 39, 40, 49, 50, 57},
           ~   1   2   3   4   5                  6   7   8   9   0  BSP
        { 27, 22, 19, 12,  9,  1},             { 30, 38, 41, 48, 51, 56},
         ESC   Q   W   E   R   T                  Y   U   I   O   P   \
        { 26, 23, 18, 13,  8,  2},             { 31, 37, 42, 47, 52, 55},
         TAB   A   S   D   F   G                  H   J   K   L   É   Á
        { 25, 24, 17, 14,  7,  3},             { 32, 36, 43, 46, 53, 54},
         SHF   Z   X   C   V   B                  N   M   ,   .   -  SHF
        {         16, 15,  6,  5,  4},     { 33, 34, 35, 44, 45}
                 WIN ALT CTR LWR SPC        ENT RSE CTR ALT WIN
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

//#ifdef SOFLE_CHOC
    const uint8_t indicators[]    = { };
    const uint8_t arrow_keys[]    = { 37, 47, 42, 41 };
    const uint8_t function_keys[] = { 21, 20, 11, 10, 0, 29, 39, 40, 49, 50, 57, 56 };
    const uint8_t lower_keys[]    = { 30, 31, 38, 48, 51, 52 };
    const uint8_t numpad_keys[]   = { 11, 10, 0, 12, 9, 1, 13, 8, 2, 14, 7, 3 };
    const uint8_t adjust_keys[]   = { 0, 1, 2, 3, 28 };
#if 0
//#else
    const uint8_t indicators[] = { 0, 1, 2, 3, 4, 5, 36, 37, 38, 39, 40, 41 };
    const uint8_t arrow_keys[] = { 64, 59, 54, 58 };

    // TODO
    const uint8_t function_keys[] = { 21, 20, 11, 10, 0, 29, 39, 40, 49, 50, 57, 56 };
    const uint8_t lower_keys[]    = { 30, 31, 38, 48, 51, 52 };
#endif
    switch(get_highest_layer(layer_state)) {
        case _QWERTY:
            SET_KEY_COLORS(indicators, 0x00, 0x00, 0x30)
        break;
        case _COLEMAK:
            SET_KEY_COLORS(indicators, 0x00, 0x00, 0x70)
        break;
        case _LOWER:
            SET_KEY_COLORS(indicators, 0x00, 0x30, 0x00)
            SET_KEY_COLORS(arrow_keys, 0x00, 0x20, 0x00)
            SET_KEY_COLORS(function_keys, 0x20, 0x20, 0x00)
            SET_KEY_COLORS(lower_keys, 0x00, 0x20, 0x20)
        break;
        case _RAISE:
            SET_KEY_COLORS(arrow_keys, 0x00, 0x20, 0x00)
            SET_KEY_COLORS(indicators, 0x30, 0x30, 0x00)
            SET_KEY_COLORS(numpad_keys, 0x00, 0x20, 0x20)
        break;
        case _ADJUST:
            SET_KEY_COLORS(arrow_keys, 0x00, 0x20, 0x00)
            SET_KEY_COLORS(indicators, 0x30, 0x00, 0x00)
//#ifdef SOFLE_CHOC
            SET_KEY_COLORS(adjust_keys, 0x20, 0x00, 0x00)
//#else
#if 0
            set_key_color(31, 0x30, 0x00, 0x00);
            set_key_color(32, 0x30, 0x00, 0x00);
#endif
        break;
    }
    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_sethsv_noeeprom(HSV_BLUE);
    rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
}
#endif
