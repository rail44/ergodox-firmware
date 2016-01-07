/* ----------------------------------------------------------------------------
 * ergoDOX layout : Dovorak (modified by rail44)
 * -----------------------------------------------------------------------------
 * Copyright (c) 2016 Satoshi Amemiya <amemiya@protonmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/rail44/ergodox-firmware>
 * -------------------------------------------------------------------------- */

#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

void kbfun_layer_pop_all(void) {
    kbfun_layer_pop_1();
    kbfun_layer_pop_2();
    kbfun_layer_pop_3();
    kbfun_layer_pop_4();
    kbfun_layer_pop_5();
    kbfun_layer_pop_6();
    kbfun_layer_pop_7();
    kbfun_layer_pop_8();
    kbfun_layer_pop_9();
    kbfun_layer_pop_10();
}

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
    KB_MATRIX_LAYER(
        0,
        KEY_DeleteForward, KEY_1_Exclamation, KEY_2_At, KEY_3_Pound, KEY_4_Dollar, KEY_5_Percent, KEY_LeftGUI,
        KEY_Tab, KEY_SingleQuote_DoubleQuote, KEY_Comma_LessThan, KEY_Period_GreaterThan, KEY_p_P, KEY_y_Y, KEY_Escape,
        KEY_LeftControl, KEY_a_A, KEY_o_O, KEY_e_E, KEY_u_U, KEY_i_I,
        KEY_LeftShift, KEY_Semicolon_Colon, KEY_q_Q, KEY_j_J, KEY_k_K, KEY_x_X, KEY_DeleteBackspace,
        KEY_LeftAlt, KEY_GraveAccent_Tilde, 0x2E, KEY_Backslash_Pipe, KEY_Slash_Question,
        KEY_CapsLock, KEY_PrintScreen,
        0, 0, KEY_LANG2,
        KEY_Spacebar, 1, KEY_LANG1,

        KEY_RightGUI, KEY_6_Caret, KEY_7_Ampersand, KEY_8_Asterisk, KEY_9_LeftParenthesis, KEY_0_RightParenthesis, KEY_DeleteForward,
        KEY_Escape, KEY_f_F, KEY_g_G, KEY_c_C, KEY_r_R, KEY_l_L, KEY_Tab,
        KEY_d_D, KEY_h_H, KEY_t_T, KEY_n_N, KEY_s_S, KEY_RightControl,
        KEY_DeleteBackspace, KEY_b_B, KEY_m_M, KEY_w_W, KEY_v_V, KEY_z_Z, KEY_RightShift,
        KEY_LeftBracket_LeftBrace, KEY_RightBracket_RightBrace, KEY_Dash_Underscore, KEY_Equal_Plus, KEY_RightAlt,
        KEY_ScrollLock, KEYPAD_NumLock_Clear,
        KEY_LANG2, 0, 0,
        KEY_LANG1, 1, KEY_ReturnEnter
    ),

    KB_MATRIX_LAYER(
        0,
        0, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, 0,
        0, 0, 0, KEY_PageUp, 0, 0, 0,
        0, 0, KEY_Home, KEY_PageDown, KEY_End, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0,
        0, 0, 0,
        0, 0, 0,

        0, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11,
        0, 0, KEY_DeleteBackspace, KEY_UpArrow, KEY_DeleteForward, 0, KEY_F12,
        0, KEY_LeftArrow, KEY_DownArrow, KEY_RightArrow, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0,
        0, 0, 0,
        0, 0, 0
    ),
};

#define kprrel &kbfun_press_release
#define ktrans &kbfun_transparent
#define lpush1 &kbfun_layer_push_1
#define lpop1 &kbfun_layer_pop_1
#define sshprre &kbfun_shift_press_release
#define s2kcap &kbfun_2_keys_capslock_press_release

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
    KB_MATRIX_LAYER(
        NULL,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, sshprre, kprrel, kprrel,
        kprrel, kprrel,
        NULL, NULL, kprrel,
        kprrel, lpush1, kprrel,

        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel,
        kprrel, NULL, NULL,
        kprrel, lpush1, kprrel
    ),

    KB_MATRIX_LAYER(
        NULL,
        NULL, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
        NULL, NULL, NULL, kprrel, NULL, NULL, NULL,
        ktrans, NULL, kprrel, kprrel, kprrel, NULL,
        ktrans, NULL, NULL, NULL, NULL, NULL, NULL,
        ktrans, NULL, NULL, NULL, NULL,
        NULL, NULL,
        NULL, NULL, NULL,
        NULL, NULL, NULL,

        ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        NULL, NULL, kprrel, kprrel, kprrel, NULL, kprrel,
        NULL, kprrel, kprrel, kprrel, NULL, ktrans,
        NULL, NULL, NULL, NULL, NULL, NULL, ktrans,
        NULL, NULL, NULL, NULL, ktrans,
        NULL, NULL,
        NULL, NULL, NULL,
        NULL, NULL, NULL
    ),
};

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {
    KB_MATRIX_LAYER(
        NULL,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, sshprre, kprrel, kprrel,
        kprrel, kprrel,
        NULL, NULL, kprrel,
        kprrel, lpop1, kprrel,

        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel,
        kprrel, NULL, NULL,
        kprrel, lpop1, kprrel
    ),

    KB_MATRIX_LAYER(
        NULL,
        NULL, kprrel, kprrel, kprrel, kprrel, kprrel, ktrans,
        NULL, NULL, NULL, kprrel, NULL, NULL, NULL,
        ktrans, NULL, kprrel, kprrel, kprrel, NULL,
        ktrans, NULL, NULL, NULL, NULL, NULL, NULL,
        ktrans, NULL, NULL, NULL, NULL,
        NULL, NULL,
        NULL, NULL, NULL,
        NULL, NULL, NULL,

        ktrans, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        NULL, NULL, kprrel, kprrel, kprrel, NULL, kprrel,
        NULL, kprrel, kprrel, kprrel, NULL, ktrans,
        NULL, NULL, NULL, NULL, NULL, NULL, ktrans,
        NULL, NULL, NULL, NULL, ktrans,
        NULL, NULL,
        NULL, NULL, NULL,
        NULL, NULL, NULL
    ),
};
