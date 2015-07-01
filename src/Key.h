#pragma once

// from      SDL_keycode_h




enum Keytype
{
    kt_undef,
    kt_toggle,
    kt_exiter,
    kt_char,
    kt_deletelast,
    kt_seperator,
    kt_number,
};

typedef Sint32  kb_key;

enum Key
{
    k_UNKNOWN = 0,
    
    k_enter = '\r',
    k_esc = '\033',
    k_backspace = '\b',
    k_tab = '\t',
    k_space = ' ',
    k_EXCLAIM = '!',
    k_QUOTEDBL = '"',
    k_HASH = '#',
    k_PERCENT = '%',
    k_DOLLAR = '$',
    k_AMPERSAND = '&',
    k_QUOTE = '\'',
    k_LEFTPAREN = '(',
    k_RIGHTPAREN = ')',
    k_ASTERISK = '*',
    k_PLUS = '+',
    k_COMMA = ',',
    k_MINUS = '-',
    k_PERIOD = '.',
    k_SLASH = '/',
    k_0 = '0',
    k_1 = '1',
    k_2 = '2',
    k_3 = '3',
    k_4 = '4',
    k_5 = '5',
    k_6 = '6',
    k_7 = '7',
    k_8 = '8',
    k_9 = '9',
    k_COLON = ':',
    k_SEMICOLON = ';',
    k_LESS = '<',
    k_EQUALS = '=',
    k_GREATER = '>',
    k_QUESTION = '?',
    k_AT = '@',
    /*
     Skip uppercase letters
     */
    k_LEFTBRACKET = '[',
    k_BACKSLASH = '\\',
    k_RIGHTBRACKET = ']',
    k_CARET = '^',
    k_UNDERSCORE = '_',
    k_BACKQUOTE = '`',
    k_a = 'a',
    k_b = 'b',
    k_c = 'c',
    k_d = 'd',
    k_e = 'e',
    k_f = 'f',
    k_g = 'g',
    k_h = 'h',
    k_i = 'i',
    k_j = 'j',
    k_k = 'k',
    k_l = 'l',
    k_m = 'm',
    k_n = 'n',
    k_o = 'o',
    k_p = 'p',
    k_q = 'q',
    k_r = 'r',
    k_s = 's',
    k_t = 't',
    k_u = 'u',
    k_v = 'v',
    k_w = 'w',
    k_x = 'x',
    k_y = 'y',
    k_z = 'z',
};



enum keyseperator
{
    ks_space = ' ' ,
};