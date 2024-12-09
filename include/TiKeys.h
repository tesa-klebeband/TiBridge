/*
 * This file is part of TiBridge (https://github.com/tesa-klebeband/TiBridge).
 * Copyright (c) 2024 tesa-klebeband.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TI_KEY_H
#define TI_KEY_H

#define KEY_RIGHT 0x01
#define KEY_LEFT 0x02
#define KEY_UP 0x03
#define KEY_DOWN 0x04
#define KEY_ENTER 0x05
#define KEY_ALPHA_ENTER 0x06
#define KEY_ALPHA_UP 0x07
#define KEY_ALPHA_DOWN 0x08
#define KEY_CLEAR 0x09
#define KEY_DEL 0x0A
#define KEY_INS 0x0B
#define KEY_RECALL 0x0C
#define KEY_LAST_ENT 0x0D
#define KEY_BOL 0x0E
#define KEY_EOL 0x0F
#define KEY_SEL_ALL 0x10
#define KEY_UNSEL_ALL 0x11
#define KEY_L_TO_TI82 0x12
#define KEY_BACKUP 0x13
#define KEY_RECEIVE 0x14
#define KEY_LNK_QUIT 0x15
#define KEY_TRANS 0x16
#define KEY_RENAME 0x17
#define KEY_OVERW 0x18
#define KEY_OMIT 0x19
#define KEY_CONT 0x1A
#define KEY_SEND_ID 0x1B
#define KEY_SEND_SW 0x1C
#define KEY_YES 0x1D
#define KEY_NO_WAY 0x1E
#define KV_SEND_TYPE 0x1F
#define KEY_OVERW_ALL 0x20
#define KEY_NO 0x25
#define KEY_K_RESET 0x26
#define KEY_APP 0x27
#define KEY_DOUG 0x28
#define KEY_LIST_FLAG 0x29
#define MENU_START 0x2B
#define KEY_ARE_YOU_SURE 0x2B
#define KEY_APPS_MENU 0x2C
#define KEY_PRGM 0x2D
#define KEY_ZOOM 0x2E
#define KEY_DRAW 0x2F
#define KEY_S_PLOT 0x30
#define KEY_STAT 0x31
#define KEY_MATH 0x32
#define KEY_TEST 0x33
#define KEY_CHAR 0x34
#define KEY_VARS 0x35
#define KEY_MEM 0x36
#define KEY_MATRIX 0x37
#define KEY_DIST 0x38
#define KEY_ANGLE 0x39
#define KEY_LIST 0x3A
#define KEY_CALC 0x3B
#define KEY_FIN 0x3C
#define MENU_END KEY_FIN
#define KEY_CATALOG 0x3E
#define KEY_INPUT_DONE 0x3F
#define KEY_OFF KEY_INPUT_DONE
#define KEY_QUIT 0x40
#define APP_START KEY_QUIT
#define KEY_LINK_IO 0x41
#define KEY_MATRIX_ED 0x42
#define KEY_STAT_ED 0x43
#define KEY_GRAPH 0x44
#define KEY_MODE 0x45
#define KEY_PRGM_ED 0x46
#define KEY_PRGM_CR 0x47
#define KEY_WINDOW 0x48
#define KEY_YEQU 0x49
#define KEY_TABLE 0x4A
#define KEY_TBL_SET 0x4B
#define KEY_CHK_RAM 0x4C
#define KEY_DEL_MEM 0x4D
#define KEY_RESET_MEM 0x4E
#define KEY_RESET_DEF 0x4F
#define KEY_PRGM_INPUT 0x50
#define KEY_Z_FACT_ED 0x51
#define KEY_ERROR 0x52
#define KEY_SOLVE_TVM 0x53
#define KEY_SOLVE_ROOT 0x54
#define KEY_STAT_P 0x55
#define KEY_INF_STAT 0x56
#define KEY_FORMAT 0x57
#define KEY_EXT_APPS 0x58
#define KEY_NEW_APPS 0x59
#define APPEND KEY_NEW_APPS
#define ECHO_START_1 0x5A
#define KEY_TRACE 0x5A
#define KEY_Z_FIT 0x5B
#define KEY_Z_IN 0x5C
#define KEY_Z_OUT 0x5D
#define KEY_Z_PREV 0x5E
#define KEY_BOX 0x5F
#define KEY_DECML 0x60
#define KEY_SET_ZM 0x61
#define KEY_SQUAR 0x62
#define KEY_STD 0x63
#define KEY_TRIG 0x64
#define KEY_USR_ZM 0x65
#define KEY_Z_STO 0x66
#define KEY_Z_INT 0x67
#define KEY_Z_STAT 0x68
#define ECHO_START_2 0x69
#define KEY_SELECT 0x69
#define KEY_CIRCL 0x6A
#define KEY_CL_DRW 0x6B
#define KEY_LINE 0x6C
#define KEY_PEN 0x6D
#define KEY_PT_CHG 0x6E
#define KEY_PT_OFF 0x6F
#define KEY_PT_ON 0x70
#define KEY_VERT 0x71
#define KEY_HORIZ 0x72
#define KEY_TEXT 0x73
#define KEY_TAN_LN 0x74
#define KEY_EVAL 0x75
#define KEY_INTERS 0x76
#define KEY_DYDX 0x77
#define KEY_FN_INTG 0x78
#define KEY_ROOT_G 0x79
#define KEY_DYDT 0x7A
#define KEY_DXDT 0x7B
#define KEY_DR_DO 0x7C
#define KEY_GF_MIN 0x7D
#define KEY_GF_MAX 0x7E
#define ECHO_START 0x7F
#define KEY_LIST_NAME 0x7F
#define KEY_ADD 0x80
#define KEY_SUB 0x81
#define KEY_MUL 0x82
#define KEY_DIV 0x83
#define KEY_EXPON 0x84
#define KEY_L_PAREN 0x85
#define KEY_R_PAREN 0x86
#define KEY_L_BRACK 0x87
#define KEY_R_BRACK 0x88
#define KEY_SHADE 0x89
#define KEY_STORE 0x8A
#define KEY_COMMA 0x8B
#define KEY_CHS 0x8C
#define KEY_DEC_PNT 0x8D
#define KEY_0 0x8E
#define KEY_1 0x8F
#define KEY_2 0x90
#define KEY_3 0x91
#define KEY_4 0x92
#define KEY_5 0x93
#define KEY_6 0x94
#define KEY_7 0x95
#define KEY_8 0x96
#define KEY_9 0x97
#define KEY_EE 0x98
#define KEY_SPACE 0x99
#define KEY_CAP_A 0x9A
#define KEY_CAP_B 0x9B
#define KEY_CAP_C 0x9C
#define KEY_CAP_D 0x9D
#define KEY_CAP_E 0x9E
#define KEY_CAP_F 0x9F
#define KEY_CAP_G 0xA0
#define KEY_CAP_H 0xA1
#define KEY_CAP_I 0xA2
#define KEY_CAP_J 0xA3
#define KEY_CAP_K 0xA4
#define KEY_CAP_L 0xA5
#define KEY_CAP_M 0xA6
#define KEY_CAP_N 0xA7
#define KEY_CAP_O 0xA8
#define KEY_CAP_P 0xA9
#define KEY_CAP_Q 0xAA
#define KEY_CAP_R 0xAB
#define KEY_CAP_S 0xAC
#define KEY_CAP_T 0xAD
#define KEY_CAP_U 0xAE
#define KEY_CAP_V 0xAF
#define KEY_CAP_W 0xB0
#define KEY_CAP_X 0xB1
#define KEY_CAP_Y 0xB2
#define KEY_CAP_Z 0xB3
#define KEY_VARX 0xB4
#define KEY_PI 0xB5
#define KEY_INV 0xB6
#define KEY_SIN 0xB7
#define KEY_ASIN 0xB8
#define KEY_COS 0xB9
#define KEY_ACOS 0xBA
#define KEY_TAN 0xBB
#define KEY_ATAN 0xBC
#define KEY_SQUARE 0xBD
#define KEY_SQRT 0xBE
#define KEY_LN 0xBF
#define KEY_EXP 0xC0
#define KEY_LOG 0xC1
#define KEY_ALOG 0xC2
#define KEY_TO_ABC 0xC3
#define KEY_CLR_TBL 0xC4
#define KEY_ANS 0xC5
#define KEY_COLON 0xC6
#define KEY_N_DERIV 0xC7
#define KEY_FN_INT 0xC8
#define KEY_ROOT 0xC9
#define KEY_QUEST 0xCA
#define KEY_QUOTE 0xCB
#define KEY_THETA 0xCC
#define KEY_IF 0xCD
#define KEY_THEN 0xCE
#define KEY_ELSE 0xCF
#define KEY_FOR 0xD0
#define KEY_WHILE 0xD1
#define KEY_REPEAT 0xD2
#define KEY_END 0xD3
#define KEY_PAUSE 0xD4
#define KEY_LBL 0xD5
#define KEY_GOTO 0xD6
#define KEY_ISG 0xD7
#define KEY_DSL 0xD8
#define KEY_MENU 0xD9
#define KEY_EXEC 0xDA
#define KEY_RETURN 0xDB
#define KEY_STOP 0xDC
#define KEY_INPUT 0xDD
#define KEY_PROMPT 0xDE
#define KEY_DISP 0xDF
#define KEY_DISP_G 0xE0
#define KEY_DISP_T 0xE1
#define KEY_OUTPUT 0xE2
#define KEY_GET_KEY 0xE3
#define KEY_CLR_HOME 0xE4
#define KEY_PRT_SCR 0xE5
#define KEY_SINH 0xE6
#define KEY_COSH 0xE7
#define KEY_TANH 0xE8
#define KEY_ASINH 0xE9
#define KEY_ACOSH 0xEA
#define KEY_ATANH 0xEB
#define KEY_L_BRACE 0xEC
#define KEY_R_BRACE 0xED
#define KEY_I 0xEE
#define KEY_CONST_E_A 0xEF
#define KEY_PLOT3 0xF0
#define KEY_F_MIN 0xF1
#define KEY_F_MAX 0xF2
#define KEY_L1A 0xF3
#define KEY_L2A 0xF4
#define KEY_L3A 0xF5
#define KEY_L4A 0xF6
#define KEY_L5A 0xF7
#define KEY_L6A 0xF8
#define KEY_UN_A 0xF9
#define KEY_VN_A 0xFA
#define KEY_WN_A 0xFB
#define KEY_E1BT 0xFE00
#define KEY_DRAW_INV KEY_E1BT
#define KEY_DRAW_F (KEY_E1BT + 1)
#define KEY_PIXEL_ON (KEY_E1BT + 2)
#define KEY_PIXEL_OFF (KEY_E1BT + 3)
#define KEY_PXL_TEST (KEY_E1BT + 4)
#define KEY_RCGDB (KEY_E1BT + 5)
#define KEY_RCPIC (KEY_E1BT + 6)
#define KEY_STGDB (KEY_E1BT + 7)
#define KEY_STPIC (KEY_E1BT + 8)
#define KEY_ABS (KEY_E1BT + 9)
#define KEY_TEQ (KEY_E1BT + 10)
#define KEY_TNOTEQ (KEY_E1BT + 11)
#define KEY_TGT (KEY_E1BT + 12)
#define KEY_TGTE (KEY_E1BT + 13)
#define KEY_TLT (KEY_E1BT + 14)
#define KEY_TLTE (KEY_E1BT + 15)
#define KEY_AND (KEY_E1BT + 16)
#define KEY_OR (KEY_E1BT + 17)
#define KEY_XOR (KEY_E1BT + 18)
#define KEY_NOT (KEY_E1BT + 19)
#define KEY_LR1 (KEY_E1BT + 20)
#define KEY_XROOT (KEY_E1BT + 21)
#define KEY_CUBE (KEY_E1BT + 22)
#define KEY_CBRT (KEY_E1BT + 23)
#define KEY_TO_DEC (KEY_E1BT + 24)
#define KEY_CUBIC_R (KEY_E1BT + 25)
#define KEY_QUART_R (KEY_E1BT + 26)
#define KEY_PLOT1 (KEY_E1BT + 27)
#define KEY_PLOT2 (KEY_E1BT + 28)
#define KEY_ROUND (KEY_E1BT + 29)
#define KEY_IPART (KEY_E1BT + 30)
#define KEY_FPART (KEY_E1BT + 31)
#define KEY_INT (KEY_E1BT + 32)
#define KEY_RAND (KEY_E1BT + 33)
#define KEY_NPR (KEY_E1BT + 34)
#define KEY_NCR (KEY_E1BT + 35)
#define KEY_X_FACTORIAL (KEY_E1BT + 36)
#define KEY_RAD (KEY_E1BT + 37)
#define KEY_DEGR (KEY_E1BT + 38)
#define KEY_A_POST (KEY_E1BT + 39)
#define KEY_TO_DMS (KEY_E1BT + 40)
#define KEY_R_TO_PO (KEY_E1BT + 41)
#define KEY_R_TO_PR (KEY_E1BT + 42)
#define KEY_P_TO_RX (KEY_E1BT + 43)
#define KEY_P_TO_RY (KEY_E1BT + 44)
#define KEY_ROW_SWAP (KEY_E1BT + 45)
#define KEY_ROW_PLUS (KEY_E1BT + 46)
#define KEY_TIM_ROW (KEY_E1BT + 47)
#define KEY_TROW_P (KEY_E1BT + 48)
#define KEY_SORT_A (KEY_E1BT + 49)
#define KEY_SORT_D (KEY_E1BT + 50)
#define KEY_SEQ (KEY_E1BT + 51)
#define KEY_MIN (KEY_E1BT + 52)
#define KEY_MAX (KEY_E1BT + 53)
#define KEY_MEAN (KEY_E1BT + 54)
#define KEY_MEDIAN (KEY_E1BT + 55)
#define KEY_SUM (KEY_E1BT + 56)
#define KEY_PROD (KEY_E1BT + 57)
#define KEY_DET (KEY_E1BT + 58)
#define KEY_TRANSP (KEY_E1BT + 59)
#define KEY_DIM (KEY_E1BT + 60)
#define KEY_FILL (KEY_E1BT + 61)
#define KEY_IDENT (KEY_E1BT + 62)
#define KEY_RANDM (KEY_E1BT + 63)
#define KEY_AUG (KEY_E1BT + 64)
#define KEY_ONE_VAR (KEY_E1BT + 65)
#define KEY_TWO_VAR (KEY_E1BT + 66)
#define KEY_LR (KEY_E1BT + 67)
#define KEY_LR_EXP (KEY_E1BT + 68)
#define KEY_LR_LN (KEY_E1BT + 69)
#define KEY_LR_PWR (KEY_E1BT + 70)
#define KEY_MED_MED (KEY_E1BT + 71)
#define KEY_QUAD (KEY_E1BT + 72)
#define KEY_CLR_LST (KEY_E1BT + 73)
#define KEY_HIST (KEY_E1BT + 74)
#define KEY_XY_LINE (KEY_E1BT + 75)
#define KEY_SCATTER (KEY_E1BT + 76)
#define KM_RAD (KEY_E1BT + 77)
#define KM_DEG (KEY_E1BT + 78)
#define KM_NORM_F (KEY_E1BT + 79)
#define KM_SCI (KEY_E1BT + 80)
#define KM_ENG (KEY_E1BT + 81)
#define KM_FLOAT (KEY_E1BT + 82)
#define KEY_FIX (KEY_E1BT + 83)
#define KEY_SPLIT_ON (KEY_E1BT + 84)
#define KEY_FULL_SCREEN (KEY_E1BT + 85)
#define KEY_STNDRD (KEY_E1BT + 86)
#define KEY_PARAM (KEY_E1BT + 87)
#define KEY_POLAR (KEY_E1BT + 88)
#define KEY_SEQ_G (KEY_E1BT + 89)
#define KEY_A_FILL_ON (KEY_E1BT + 90)
#define KEY_A_FILL_OFF (KEY_E1BT + 91)
#define KEY_A_CALC_ON (KEY_E1BT + 92)
#define KEY_A_CALC_OFF (KEY_E1BT + 93)
#define KEY_FN_ON (KEY_E1BT + 94)
#define KEY_FN_OFF (KEY_E1BT + 95)
#define KEY_PLOTS_ON (KEY_E1BT + 96)
#define KEY_PLOTS_OFF (KEY_E1BT + 97)
#define KEY_PIXEL_CHG (KEY_E1BT + 98)
#define KEY_SEND_MBL (KEY_E1BT + 99)
#define KEY_RECV_MBL (KEY_E1BT + 100)
#define KEY_BOX_PLOT (KEY_E1BT + 101)
#define KEY_BOX_ICON (KEY_E1BT + 102)
#define KEY_CROSS_ICON (KEY_E1BT + 103)
#define KEY_DOT_ICON (KEY_E1BT + 104)
#define KEY_E2BT (KEY_E1BT + 105)
#define KEY_SEQENTIAL KEY_E2BT
#define KEY_SIMUL_G (KEY_E2BT + 1)
#define KEY_POLAR_G (KEY_E2BT + 2)
#define KEY_RECT_G (KEY_E2BT + 3)
#define KEY_COORD_ON (KEY_E2BT + 4)
#define KEY_COORD_OFF (KEY_E2BT + 5)
#define KEY_DRAW_LINE (KEY_E2BT + 6)
#define KEY_DRAW_DOT (KEY_E2BT + 7)
#define KEY_AXIS_ON (KEY_E2BT + 8)
#define KEY_AXIS_OFF (KEY_E2BT + 9)
#define KEY_GRID_ON (KEY_E2BT + 10)
#define KEY_GRID_OFF (KEY_E2BT + 11)
#define KEY_LBL_ON (KEY_E2BT + 12)
#define KEY_LBL_OFF (KEY_E2BT + 13)
#define KEY_L1 (KEY_E2BT + 14)
#define KEY_L2 (KEY_E2BT + 15)
#define KEY_L3 (KEY_E2BT + 16)
#define KEY_L4 (KEY_E2BT + 17)
#define KEY_L5 (KEY_E2BT + 18)
#define KEY_L6 (KEY_E2BT + 19)
#define KEY_INF_DATA (KEY_L1 + 0x0)
#define KEY_INF_STATS (KEY_L1 + 0x1)
#define KEY_INF_YES (KEY_L1 + 0x2)
#define KEY_INF_NO (KEY_L1 + 0x3)
#define KEY_INF_CALC (KEY_L1 + 0x4)
#define KEY_INF_DRAW (KEY_L1 + 0x5)
#define KEY_INF_ALT1_NE (KEY_L1 + 0x6)
#define KEY_INF_ALT1_LT (KEY_L1 + 0x7)
#define KEY_INF_ALT1_GT (KEY_L1 + 0x8)
#define KEY_INF_ALT2_NE (KEY_L1 + 0x9)
#define KEY_INF_ALT2_LT (KEY_L1 + 0xA)
#define KEY_INF_ALT2_GT (KEY_L1 + 0xB)
#define KEY_INF_ALT3_NE (KEY_L1 + 0xC)
#define KEY_INF_ALT3_LT (KEY_L1 + 0xD)
#define KEY_INF_ALT3_GT (KEY_L1 + 0xE)
#define KEY_INF_ALT4_NE (KEY_L1 + 0xF)
#define KEY_INF_ALT4_LT (KEY_L1 + 0x10)
#define KEY_INF_ALT4_GT (KEY_L1 + 0x11)
#define KEY_INF_ALT5_NE (KEY_L1 + 0x12)
#define KEY_INF_ALT5_LT (KEY_L1 + 0x13)
#define KEY_INF_ALT5_GT (KEY_L1 + 0x14)
#define KEY_INF_ALT6_NE (KEY_L1 + 0x15)
#define KEY_INF_ALT6_LT (KEY_L1 + 0x16)
#define KEY_INF_ALT6_GT (KEY_L1 + 0x17)
#define KEY_MAT_A (KEY_E2BT + 20)
#define KEY_MAT_B (KEY_E2BT + 21)
#define KEY_MAT_C (KEY_E2BT + 22)
#define KEY_MAT_D (KEY_E2BT + 23)
#define KEY_MAT_E (KEY_E2BT + 24)
#define KEY_XMIN (KEY_E2BT + 25)
#define KEY_XMAX (KEY_E2BT + 26)
#define KEY_XSCL (KEY_E2BT + 27)
#define KEY_YMIN (KEY_E2BT + 28)
#define KEY_YMAX (KEY_E2BT + 29)
#define KEY_YSCL (KEY_E2BT + 30)
#define KEY_TMIN (KEY_E2BT + 31)
#define KEY_TMAX (KEY_E2BT + 32)
#define KEY_TSTEP (KEY_E2BT + 33)
#define KEY_OMIN (KEY_E2BT + 34)
#define KEY_OMAX (KEY_E2BT + 35)
#define KEY_OSTEP (KEY_E2BT + 36)
#define KEY_U0 (KEY_E2BT + 37)
#define KEY_V0 (KEY_E2BT + 38)
#define KEY_NMIN (KEY_E2BT + 39)
#define KEY_NMAX (KEY_E2BT + 40)
#define KEY_DELTA_Y (KEY_E2BT + 41)
#define KEY_DELTA_X (KEY_E2BT + 42)
#define KEY_ZXMIN (KEY_E2BT + 43)
#define KEY_ZXMAX (KEY_E2BT + 44)
#define KEY_ZXSCL (KEY_E2BT + 45)
#define KEY_ZYMIN (KEY_E2BT + 46)
#define KEY_ZYMAX (KEY_E2BT + 47)
#define KEY_ZYSCL (KEY_E2BT + 48)
#define KEY_ZTMIN (KEY_E2BT + 49)
#define KEY_ZTMAX (KEY_E2BT + 50)
#define KEY_ZTSTEP (KEY_E2BT + 51)
#define KEY_ZOMIN (KEY_E2BT + 52)
#define KEY_ZOMAX (KEY_E2BT + 53)
#define KEY_ZOSTEP (KEY_E2BT + 54)
#define KEY_ZU0 (KEY_E2BT + 55)
#define KEY_ZV0 (KEY_E2BT + 56)
#define KEY_ZNMIN (KEY_E2BT + 57)
#define KEY_ZNMAX (KEY_E2BT + 58)
#define KEY_DEL_LAST (KEY_E2BT + 59)
#define KEY_SIN_REG (KEY_E2BT + 60)
#define KEY_CONST_E (KEY_E2BT + 61)
#define KEY_PIC_1 (KEY_E2BT + 62)
#define KEY_PIC_2 (KEY_E2BT + 63)
#define KEY_PIC_3 (KEY_E2BT + 64)
#define KEY_DEL_VAR (KEY_E2BT + 65)
#define KEY_GET_CALC (KEY_E2BT + 66)
#define KEY_REAL_M (KEY_E2BT + 67)
#define KEY_POLAR_M (KEY_E2BT + 68)
#define KEY_RECT_M (KEY_E2BT + 69)
#define KEY_UV (KEY_E2BT + 70)
#define KEY_VW (KEY_E2BT + 71)
#define KEY_UW (KEY_E2BT + 72)
#define KEY_FIN_PMT_END (KEY_E2BT + 73)
#define KEY_FIN_PMT_BEG (KEY_E2BT + 74)
#define KEY_GRAPH_STYLE (KEY_E2BT + 75)
#define KEY_EXPR_ON (KEY_E2BT + 76)
#define KEY_EXPR_OFF (KEY_E2BT + 77)
#define KEY_STAT_A (KEY_E2BT + 78)
#define KEY_STAT_B (KEY_E2BT + 79)
#define KEY_STAT_C (KEY_E2BT + 80)
#define KEY_CORR (KEY_E2BT + 81)
#define KEY_STAT_D (KEY_E2BT + 82)
#define KEY_STAT_E (KEY_E2BT + 83)
#define KEY_REG_EQ (KEY_E2BT + 84)
#define KEY_MIN_X (KEY_E2BT + 85)
#define KEY_Q1 (KEY_E2BT + 86)
#define KEY_MD (KEY_E2BT + 87)
#define KEY_Q3 (KEY_E2BT + 88)
#define KEY_MAX_X (KEY_E2BT + 89)
#define KEY_STAT_X1 (KEY_E2BT + 90)
#define KEY_STAT_Y1 (KEY_E2BT + 91)
#define KEY_STAT_X2 (KEY_E2BT + 92)
#define KEY_STAT_Y2 (KEY_E2BT + 93)
#define KEY_STAT_X3 (KEY_E2BT + 94)
#define KEY_STAT_Y3 (KEY_E2BT + 95)
#define KEY_TBL_MIN (KEY_E2BT + 96)
#define KEY_TBL_STEP (KEY_E2BT + 97)
#define KEY_SETUP_LST (KEY_E2BT + 98)
#define KEY_CLR_ALL_LST (KEY_E2BT + 99)
#define KEY_LOGISTIC (KEY_E2BT + 100)
#define KEY_Z_TEST (KEY_E2BT + 101)
#define KEY_T_TEST (KEY_E2BT + 102)
#define KEY_2SAMP_Z_TEST (KEY_E2BT + 103)
#define KEY_2SAMP_T_TEST (KEY_E2BT + 104)
#define KEY_1PROP_Z_TEST (KEY_E2BT + 105)
#define KEY_2PROP_Z_TEST (KEY_E2BT + 106)
#define KEY_CHI_TEST (KEY_E2BT + 107)
#define KEY_2SAMP_F_TEST (KEY_E2BT + 108)
#define KEY_Z_INT_VAL (KEY_E2BT + 109)
#define KEY_T_INT_VAL (KEY_E2BT + 110)
#define KEY_2SAMP_T_INT (KEY_E2BT + 111)
#define KEY_2SAMP_Z_INT (KEY_E2BT + 112)
#define KEY_1PROP_Z_INT (KEY_E2BT + 113)
#define KEY_2PROP_Z_INT (KEY_E2BT + 114)
#define KEY_D_NORMAL (KEY_E2BT + 115)
#define KEY_INV_NORM (KEY_E2BT + 116)
#define KEY_DT (KEY_E2BT + 117)
#define KEY_CHI (KEY_E2BT + 118)
#define KEY_DF (KEY_E2BT + 119)
#define KEY_BIN_PDF (KEY_E2BT + 120)
#define KEY_BIN_CDF (KEY_E2BT + 121)
#define KEY_POI_PDF (KEY_E2BT + 122)
#define KEY_POI_CDF (KEY_E2BT + 123)
#define KEY_U_N (KEY_E2BT + 124)
#define KEY_V_N (KEY_E2BT + 125)
#define KEY_W_N (KEY_E2BT + 126)
#define KEY_REC_N (KEY_E2BT + 127)
#define KEY_PLOT_START (KEY_E2BT + 128)
#define KEY_Z_PLOT_START (KEY_E2BT + 129)
#define KEY_X_FACT (KEY_E2BT + 130)
#define KEY_Y_FACT (KEY_E2BT + 131)
#define KEY_ANOVA (KEY_E2BT + 132)
#define KEY_MAX_Y (KEY_E2BT + 133)
#define KEY_WEB_ON (KEY_E2BT + 134)
#define KEY_WEB_OFF (KEY_E2BT + 135)
#define KEY_TBL_INPUT (KEY_E2BT + 136)
#define KEY_GEO_PDF (KEY_E2BT + 137)
#define KEY_GEO_CDF (KEY_E2BT + 138)
#define KEY_SHADE_NORM (KEY_E2BT + 139)
#define KEY_SHADE_T (KEY_E2BT + 140)
#define KEY_SHADE_CHI (KEY_E2BT + 141)
#define KEY_SHADE_F (KEY_E2BT + 142)
#define KEY_PLOT_STEP (KEY_E2BT + 143)
#define KEY_Z_PLOT_STEP (KEY_E2BT + 144)
#define KEY_LIN_REG_T_TEST (KEY_E2BT + 145)
#define KEY_MGT (KEY_E2BT + 146)
#define KEY_SELECT_A (KEY_E2BT + 147)
#define KEY_Z_FIT_A (KEY_E2BT + 148)
#define KEY_E2BT_END KEY_Z_FIT_A
#define KEY_E2BT2 0xFC00
#define KEY_GDB1 KEY_E2BT2
#define KEY_GDB2 (KEY_E2BT2 + 1)
#define KEY_GDB3 (KEY_E2BT2 + 2)
#define KEY_Y1 (KEY_E2BT2 + 3)
#define KEY_Y2 (KEY_E2BT2 + 4)
#define KEY_Y3 (KEY_E2BT2 + 5)
#define KEY_Y4 (KEY_E2BT2 + 6)
#define KEY_Y5 (KEY_E2BT2 + 7)
#define KEY_Y6 (KEY_E2BT2 + 8)
#define KEY_Y7 (KEY_E2BT2 + 9)
#define KEY_Y8 (KEY_E2BT2 + 10)
#define KEY_Y9 (KEY_E2BT2 + 11)
#define KEY_Y0 (KEY_E2BT2 + 12)
#define KEY_X1T (KEY_E2BT2 + 13)
#define KEY_Y1T (KEY_E2BT2 + 14)
#define KEY_X2T (KEY_E2BT2 + 15)
#define KEY_Y2T (KEY_E2BT2 + 16)
#define KEY_X3T (KEY_E2BT2 + 17)
#define KEY_Y3T (KEY_E2BT2 + 18)
#define KEY_X4T (KEY_E2BT2 + 19)
#define KEY_Y4T (KEY_E2BT2 + 20)
#define KEY_X5T (KEY_E2BT2 + 21)
#define KEY_Y5T (KEY_E2BT2 + 22)
#define KEY_X6T (KEY_E2BT2 + 23)
#define KEY_Y6T (KEY_E2BT2 + 24)
#define KEY_R1 (KEY_E2BT2 + 25)
#define KEY_R2 (KEY_E2BT2 + 26)
#define KEY_R3 (KEY_E2BT2 + 27)
#define KEY_R4 (KEY_E2BT2 + 28)
#define KEY_R5 (KEY_E2BT2 + 29)
#define KEY_R6 (KEY_E2BT2 + 30)
#define KEY_GDB4 (KEY_E2BT2 + 31)
#define KEY_GDB5 (KEY_E2BT2 + 32)
#define KEY_GDB6 (KEY_E2BT2 + 33)
#define KEY_PIC4 (KEY_E2BT2 + 34)
#define KEY_PIC5 (KEY_E2BT2 + 35)
#define KEY_PIC6 (KEY_E2BT2 + 36)
#define KEY_GDB7 (KEY_E2BT2 + 37)
#define KEY_GDB8 (KEY_E2BT2 + 38)
#define KEY_GDB9 (KEY_E2BT2 + 39)
#define KEY_GDB0 (KEY_E2BT2 + 40)
#define KEY_PIC7 (KEY_E2BT2 + 41)
#define KEY_PIC8 (KEY_E2BT2 + 42)
#define KEY_PIC9 (KEY_E2BT2 + 43)
#define KEY_PIC0 (KEY_E2BT2 + 44)
#define KEY_STATN (KEY_E2BT2 + 45)
#define KEY_XMEAN (KEY_E2BT2 + 46)
#define KEY_CONJ (KEY_E2BT2 + 47)
#define KEY_REAL (KEY_E2BT2 + 48)
#define KEY_FANGLE (KEY_E2BT2 + 49)
#define KEY_LCM (KEY_E2BT2 + 50)
#define KEY_GCD (KEY_E2BT2 + 51)
#define KEY_RANDINT (KEY_E2BT2 + 52)
#define KEY_RANDNORM (KEY_E2BT2 + 53)
#define KEY_TOPOLAR (KEY_E2BT2 + 54)
#define KEY_TORECT (KEY_E2BT2 + 55)
#define KEY_YMEAN (KEY_E2BT2 + 56)
#define KEY_STDX (KEY_E2BT2 + 57)
#define KEY_STDX1 (KEY_E2BT2 + 58)
#define KW0 (KEY_E2BT2 + 59)
#define KEY_MATF (KEY_E2BT2 + 60)
#define KEY_MATG (KEY_E2BT2 + 61)
#define KEY_MATRH (KEY_E2BT2 + 62)
#define KEY_MATI (KEY_E2BT2 + 63)
#define KEY_MATJ (KEY_E2BT2 + 64)
#define KEY_YMEAN1 (KEY_E2BT2 + 65)
#define KEY_STDY (KEY_E2BT2 + 66)
#define KEY_STDY1 (KEY_E2BT2 + 67)
#define KEY_MAT2LST (KEY_E2BT2 + 68)
#define KEY_LST2MAT (KEY_E2BT2 + 69)
#define KEY_CUMSUM (KEY_E2BT2 + 70)
#define KEY_DELTALST (KEY_E2BT2 + 71)
#define KEY_STDDEV (KEY_E2BT2 + 72)
#define KEY_VARIANCE (KEY_E2BT2 + 73)
#define KEY_LENGTH (KEY_E2BT2 + 74)
#define KEY_EQU2STRNG (KEY_E2BT2 + 75)
#define KEY_STRNG2EQU (KEY_E2BT2 + 76)
#define KEY_EXPR (KEY_E2BT2 + 77)
#define KEY_SUBSTRNG (KEY_E2BT2 + 78)
#define KEY_INSTRNG (KEY_E2BT2 + 79)
#define KEY_STR1 (KEY_E2BT2 + 80)
#define KEY_STR2 (KEY_E2BT2 + 81)
#define KEY_STR3 (KEY_E2BT2 + 82)
#define KEY_STR4 (KEY_E2BT2 + 83)
#define KEY_STR5 (KEY_E2BT2 + 84)
#define KEY_STR6 (KEY_E2BT2 + 85)
#define KEY_STR7 (KEY_E2BT2 + 86)
#define KEY_STR8 (KEY_E2BT2 + 87)
#define KEY_STR9 (KEY_E2BT2 + 88)
#define KEY_STR0 (KEY_E2BT2 + 89)
#define KEY_FINN (KEY_E2BT2 + 90)
#define KEY_FINI (KEY_E2BT2 + 91)
#define KEY_FINPV (KEY_E2BT2 + 92)
#define KEY_FINPMT (KEY_E2BT2 + 93)
#define KEY_FINFV (KEY_E2BT2 + 94)
#define KEY_FINPY (KEY_E2BT2 + 95)
#define KEY_FINCY (KEY_E2BT2 + 96)
#define KEY_FINFPMT (KEY_E2BT2 + 97)
#define KEY_FINFI (KEY_E2BT2 + 98)
#define KEY_FINFPV (KEY_E2BT2 + 99)
#define KEY_FINFN (KEY_E2BT2 + 100)
#define KEY_FINFFV (KEY_E2BT2 + 101)
#define KEY_FINNPV (KEY_E2BT2 + 102)
#define KEY_FINIRR (KEY_E2BT2 + 103)
#define KEY_FINBAL (KEY_E2BT2 + 104)
#define KEY_FINPRN (KEY_E2BT2 + 105)
#define KEY_FININT (KEY_E2BT2 + 106)
#define KEY_SUMX (KEY_E2BT2 + 107)
#define KEY_SUMX2 (KEY_E2BT2 + 108)
#define KEY_FINTONOM (KEY_E2BT2 + 109)
#define KEY_FINTOEFF (KEY_E2BT2 + 110)
#define KEY_FINDBD (KEY_E2BT2 + 111)
#define KEY_STATVP (KEY_E2BT2 + 112)
#define KEY_STATZ (KEY_E2BT2 + 113)
#define KEY_STATT (KEY_E2BT2 + 114)
#define KEY_STATCHI (KEY_E2BT2 + 115)
#define KEY_STATF (KEY_E2BT2 + 116)
#define KEY_STATDF (KEY_E2BT2 + 117)
#define KEY_STATPHAT (KEY_E2BT2 + 118)
#define KEY_STATPHAT1 (KEY_E2BT2 + 119)
#define KEY_STATPHAT2 (KEY_E2BT2 + 120)
#define KEY_STATMEANX1 (KEY_E2BT2 + 121)
#define KEY_STATMEANX2 (KEY_E2BT2 + 122)
#define KEY_STATSTDX1 (KEY_E2BT2 + 123)
#define KEY_STATSTDX2 (KEY_E2BT2 + 124)
#define KEY_STATSTDXP (KEY_E2BT2 + 125)
#define KEY_STATN1 (KEY_E2BT2 + 126)
#define KEY_STATN2 (KEY_E2BT2 + 127)
#define KEY_STATLOWER (KEY_E2BT2 + 128)
#define KEY_STATUPPER (KEY_E2BT2 + 129)
#define KUW0 (KEY_E2BT2 + 130)
#define KEY_IMAG (KEY_E2BT2 + 131)
#define KEY_SUMY (KEY_E2BT2 + 132)
#define KEY_XRES (KEY_E2BT2 + 133)
#define KEY_STAT_S (KEY_E2BT2 + 134)
#define KEY_SUMY2 (KEY_E2BT2 + 135)
#define KEY_SUMXY (KEY_E2BT2 + 136)
#define KEY_UXRES (KEY_E2BT2 + 137)
#define KEY_MODBOX (KEY_E2BT2 + 138)
#define KEY_NORMPROB (KEY_E2BT2 + 139)
#define KEY_NORMAL_PDF (KEY_E2BT2 + 140)
#define KEY_TPDF (KEY_E2BT2 + 141)
#define KEY_CHI_PDF (KEY_E2BT2 + 142)
#define KEY_FPDF (KEY_E2BT2 + 143)
#define KEY_MIN_Y (KEY_E2BT2 + 144)
#define KEY_RAND_BIN (KEY_E2BT2 + 145)
#define KEY_REF (KEY_E2BT2 + 146)
#define KEY_R_REF (KEY_E2BT2 + 147)
#define KEY_LRSQR (KEY_E2BT2 + 148)
#define KEY_BRSQR (KEY_E2BT2 + 149)
#define KEY_DIAG_ON (KEY_E2BT2 + 150)
#define KEY_DIAG_OFF (KEY_E2BT2 + 151)
#define KUN1 (KEY_E2BT2 + 152)
#define KEY_VN1 (KEY_E2BT2 + 153)
#define K83_00_END (KEY_VN1)
#define KEY_ARCHIVE (K83_00_END + 1)
#define KEY_UNARCHIVE (K83_00_END + 2)
#define KEY_ASM (K83_00_END + 3)
#define KEY_ASM_PRGM (K83_00_END + 4)
#define KEY_ASM_COMP (K83_00_END + 5)
#define KEY_CAP_A_ACUTE (K83_00_END + 6)
#define KEY_CAP_A_GRAVE (K83_00_END + 7)
#define KEY_CAP_A_CARET (K83_00_END + 8)
#define KEY_CAP_A_DIER (K83_00_END + 9)
#define KEY_A_ACUTE (K83_00_END + 10)
#define KEY_A_GRAVE (K83_00_END + 11)
#define KEY_A_CARET (K83_00_END + 12)
#define KEY_A_DIER (K83_00_END + 13)
#define KEY_CAP_E_ACUTE (K83_00_END + 14)
#define KEY_CAP_E_GRAVE (K83_00_END + 15)
#define KEY_CAP_E_CARET (K83_00_END + 16)
#define KEY_CAP_E_DIER (K83_00_END + 17)
#define KEY_E_ACUTE (K83_00_END + 18)
#define KEY_E_GRAVE (K83_00_END + 19)
#define KEY_E_CARET (K83_00_END + 20)
#define KEY_E_DIER (K83_00_END + 21)
#define KEY_CAP_I_ACUTE (K83_00_END + 22)
#define KEY_CAP_I_GRAVE (K83_00_END + 23)
#define KEY_CAP_I_CARET (K83_00_END + 24)
#define KEY_CAP_I_DIER (K83_00_END + 25)
#define KEY_I_ACUTE (K83_00_END + 26)
#define KEY_I_GRAVE (K83_00_END + 27)
#define KEY_I_CARET (K83_00_END + 28)
#define KEY_I_DIER (K83_00_END + 29)
#define KEY_CAP_O_ACUTE (K83_00_END + 30)
#define KEY_CAP_O_GRAVE (K83_00_END + 31)
#define KEY_CAP_O_CARET (K83_00_END + 32)
#define KEY_CAP_O_DIER (K83_00_END + 33)
#define KEY_O_ACUTE (K83_00_END + 34)
#define KEY_O_GRAVE (K83_00_END + 35)
#define KEY_O_CARET (K83_00_END + 36)
#define KEY_O_DIER (K83_00_END + 37)
#define KEY_CAP_U_ACUTE (K83_00_END + 38)
#define KEY_CAP_U_GRAVE (K83_00_END + 39)
#define KEY_CAP_U_CARET (K83_00_END + 40)
#define KEY_CAP_U_DIER (K83_00_END + 41)
#define KEY_U_ACUTE (K83_00_END + 42)
#define KEY_U_GRAVE (K83_00_END + 43)
#define KEY_U_CARET (K83_00_END + 44)
#define KEY_U_DIER (K83_00_END + 45)
#define KEY_CAP_C_CED (K83_00_END + 46)
#define KEY_C_CED (K83_00_END + 47)
#define KEY_CAP_N_TILDE (K83_00_END + 48)
#define KEY_N_TILDE (K83_00_END + 49)
#define KEY_ACCENT (K83_00_END + 50)
#define KEY_GRAVE (K83_00_END + 51)
#define KEY_DIERESIS (K83_00_END + 52)
#define KEY_QUES_DOWN (K83_00_END + 53)
#define KEY_EXCLAM_DOWN (K83_00_END + 54)
#define KEY_ALPHA (K83_00_END + 55)
#define KEY_BETA (K83_00_END + 56)
#define KEY_GAMMA (K83_00_END + 57)
#define KEY_CAP_DELTA (K83_00_END + 58)
#define KEY_DELTA (K83_00_END + 59)
#define KEY_EPSILON (K83_00_END + 60)
#define KEY_LAMBDA (K83_00_END + 61)
#define KEY_MU (K83_00_END + 62)
#define KEY_PI2 (K83_00_END + 63)
#define KEY_RHO (K83_00_END + 64)
#define KEY_CAP_SIGMA (K83_00_END + 65)
#define KEY_SIGMA (K83_00_END + 66)
#define KEY_TAU (K83_00_END + 67)
#define KEY_PHI (K83_00_END + 68)
#define KEY_CAP_OMEGA (K83_00_END + 69)
#define KEY_PHAT (K83_00_END + 70)
#define KEY_CHI2 (K83_00_END + 71)
#define KEY_STAT_F2 (K83_00_END + 72)
#define KEY_LA (K83_00_END + 73)
#define KEY_LB (K83_00_END + 74)
#define KEY_LC (K83_00_END + 75)
#define KEY_LD (K83_00_END + 76)
#define KEY_LE (K83_00_END + 77)
#define KEY_LF (K83_00_END + 78)
#define KEY_LG (K83_00_END + 79)
#define KEY_LH (K83_00_END + 80)
#define KEY_LI (K83_00_END + 81)
#define KEY_LJ (K83_00_END + 82)
#define KEY_LK (K83_00_END + 83)
#define KEY_LL (K83_00_END + 84)
#define KEY_LM (K83_00_END + 85)
#define KEY_LSMALLN (K83_00_END + 86)
#define KEY_LO (K83_00_END + 87)
#define KEY_LP (K83_00_END + 88)
#define KEY_LQ (K83_00_END + 89)
#define KEY_LSMALLR (K83_00_END + 90)
#define KEY_LS (K83_00_END + 91)
#define KEY_LT (K83_00_END + 92)
#define KEY_LU (K83_00_END + 93)
#define KEY_LV (K83_00_END + 94)
#define KEY_LW (K83_00_END + 95)
#define KEY_LX (K83_00_END + 96)
#define KEY_LY (K83_00_END + 97)
#define KEY_LZ (K83_00_END + 98)
#define KEY_GARBAGE_C (K83_00_END + 99)
#define KEY_E2BT2_END (KEY_GARBAGE_C)
#define KEY_E2BT3 0xFB00
#define KEY_RESERVED (KEY_E2BT3 + 1)
#define KEY_AT_SIGN (KEY_E2BT3 + 2)
#define KEY_POUND (KEY_E2BT3 + 3)
#define KEY_DOLLAR (KEY_E2BT3 + 4)
#define KEY_AMPERSAND (KEY_E2BT3 + 5)
#define KEY_BACK_QUOTE (KEY_E2BT3 + 6)
#define KEY_SEMICOLON (KEY_E2BT3 + 7)
#define KEY_BACK_SLASH (KEY_E2BT3 + 8)
#define KEY_VERT_SLASH (KEY_E2BT3 + 9)
#define KEY_UNDERSCORE (KEY_E2BT3 + 10)
#define KEY_TILDE (KEY_E2BT3 + 11)
#define KEY_PERCENT (KEY_E2BT3 + 12)
#define KEY_LAST_USED_K3 KEY_PERCENT
#define KEY_TAB (KEY_E2BT3 + 13)
#define KEY_SHFT_TAB (KEY_E2BT3 + 14)
#define KEY_SHFT_DEL (KEY_E2BT3 + 15)
#define KEY_SHFT_BACK (KEY_E2BT3 + 16)
#define KEY_SHFT_PG_UP (KEY_E2BT3 + 17)
#define KEY_SHFT_PG_DN (KEY_E2BT3 + 18)
#define KEY_SHFT_LEFT (KEY_E2BT3 + 19)
#define KEY_SHFT_RIGHT (KEY_E2BT3 + 20)
#define KEY_SHFT_UP (KEY_E2BT3 + 21)
#define KEY_SHFT_DN (KEY_E2BT3 + 22)
#define KEY_DIAMOND (KEY_E2BT3 + 23)
#define KEY_DIA_ADD (KEY_DIAMOND + 0)
#define KEY_DIA_SUB (KEY_DIAMOND + 1)
#define KEY_DIA_TILDE (KEY_DIAMOND + 2)
#define KEY_DIA_DIV (KEY_DIAMOND + 3)
#define KEY_DIA_BK_SLASH (KEY_DIAMOND + 4)
#define KEY_DIA_COLON (KEY_DIAMOND + 5)
#define KEY_DIA_QUOTE (KEY_DIAMOND + 6)
#define KEY_DIA_L_BRACK (KEY_DIAMOND + 7)
#define KEY_DIA_R_BRACK (KEY_DIAMOND + 8)
#define KEY_DIA_BK_SPACE (KEY_DIAMOND + 9)
#define KEY_DIA_ENTER (KEY_DIAMOND + 10)
#define KEY_DIA_COMMA (KEY_DIAMOND + 11)
#define KEY_DIA_DEL (KEY_DIAMOND + 12)
#define KEY_DIA_DEC_PNT (KEY_DIAMOND + 13)
#define KEY_DIA_0 (KEY_DIAMOND + 14)
#define KEY_DIA_1 (KEY_DIAMOND + 15)
#define KEY_DIA_2 (KEY_DIAMOND + 16)
#define KEY_DIA_3 (KEY_DIAMOND + 17)
#define KEY_DIA_4 (KEY_DIAMOND + 18)
#define KEY_DIA_5 (KEY_DIAMOND + 19)
#define KEY_DIA_6 (KEY_DIAMOND + 20)
#define KEY_DIA_7 (KEY_DIAMOND + 21)
#define KEY_DIA_8 (KEY_DIAMOND + 22)
#define KEY_DIA_9 (KEY_DIAMOND + 23)
#define KEY_DIA_TAB (KEY_DIAMOND + 24)
#define KEY_DIA_SPACE (KEY_DIAMOND + 25)
#define KEY_DIA_A (KEY_DIAMOND + 26)
#define KEY_DIA_B (KEY_DIAMOND + 27)
#define KEY_DIA_C (KEY_DIAMOND + 28)
#define KEY_DIA_D (KEY_DIAMOND + 29)
#define KEY_DIA_E (KEY_DIAMOND + 30)
#define KEY_DIA_F (KEY_DIAMOND + 31)
#define KEY_DIA_G (KEY_DIAMOND + 32)
#define KEY_DIA_H (KEY_DIAMOND + 33)
#define KEY_DIA_I (KEY_DIAMOND + 34)
#define KEY_DIA_J (KEY_DIAMOND + 35)
#define KEY_DIA_K (KEY_DIAMOND + 36)
#define KEY_DIA_L (KEY_DIAMOND + 37)
#define KEY_DIA_M (KEY_DIAMOND + 38)
#define KEY_DIA_N (KEY_DIAMOND + 39)
#define KEY_DIA_O (KEY_DIAMOND + 40)
#define KEY_DIA_P (KEY_DIAMOND + 41)
#define KEY_DIA_Q (KEY_DIAMOND + 42)
#define KEY_DIA_R (KEY_DIAMOND + 43)
#define KEY_DIA_S (KEY_DIAMOND + 44)
#define KEY_DIA_T (KEY_DIAMOND + 45)
#define KEY_DIA_U (KEY_DIAMOND + 46)
#define KEY_DIA_V (KEY_DIAMOND + 47)
#define KEY_DIA_W (KEY_DIAMOND + 48)
#define KEY_DIA_X (KEY_DIAMOND + 49)
#define KEY_DIA_Y (KEY_DIAMOND + 50)
#define KEY_DIA_Z (KEY_DIAMOND + 51)
#define KEY_DIA_PG_UP (KEY_DIAMOND + 52)
#define KEY_DIA_PG_DN (KEY_DIAMOND + 53)
#define KEY_DIA_LEFT (KEY_DIAMOND + 54)
#define KEY_DIA_RIGHT (KEY_DIAMOND + 55)
#define KEY_DIA_UP (KEY_DIAMOND + 56)
#define KEY_DIA_DN (KEY_DIAMOND + 57)
#define KEY_DB_SQUARE (KEY_DIAMOND + 58)
#define KEY_SQR_ADD (KEY_DB_SQUARE + 0)
#define KEY_SQR_SUB (KEY_DB_SQUARE + 1)
#define KEY_SQR_TILDE (KEY_DB_SQUARE + 2)
#define KEY_SQR_DIV (KEY_DB_SQUARE + 3)
#define KEY_SQR_BK_SLASH (KEY_DB_SQUARE + 4)
#define KEY_SQR_COLON (KEY_DB_SQUARE + 5)
#define KEY_SQR_QUOTE (KEY_DB_SQUARE + 6)
#define KEY_SQR_L_BRACK (KEY_DB_SQUARE + 7)
#define KEY_SQR_R_BRACK (KEY_DB_SQUARE + 8)
#define KEY_SQR_BK_SPACE (KEY_DB_SQUARE + 9)
#define KEY_SQR_ENTER (KEY_DB_SQUARE + 10)
#define KEY_SQR_COMMA (KEY_DB_SQUARE + 11)
#define KEY_SQR_DEL (KEY_DB_SQUARE + 12)
#define KEY_SQR_DEC_PNT (KEY_DB_SQUARE + 13)
#define KEY_SQR_0 (KEY_DB_SQUARE + 14)
#define KEY_SQR_1 (KEY_DB_SQUARE + 15)
#define KEY_SQR_2 (KEY_DB_SQUARE + 16)
#define KEY_SQR_3 (KEY_DB_SQUARE + 17)
#define KEY_SQR_4 (KEY_DB_SQUARE + 18)
#define KEY_SQR_5 (KEY_DB_SQUARE + 19)
#define KEY_SQR_6 (KEY_DB_SQUARE + 20)
#define KEY_SQR_7 (KEY_DB_SQUARE + 21)
#define KEY_SQR_8 (KEY_DB_SQUARE + 22)
#define KEY_SQR_9 (KEY_DB_SQUARE + 23)
#define KEY_SQR_TAB (KEY_DB_SQUARE + 24)
#define KEY_SQR_SPACE (KEY_DB_SQUARE + 25)
#define KEY_SQR_A (KEY_DB_SQUARE + 26)
#define KEY_SQR_B (KEY_DB_SQUARE + 27)
#define KEY_SQR_C (KEY_DB_SQUARE + 28)
#define KEY_SQR_D (KEY_DB_SQUARE + 29)
#define KEY_SQR_E (KEY_DB_SQUARE + 30)
#define KEY_SQR_F (KEY_DB_SQUARE + 31)
#define KEY_SQR_G (KEY_DB_SQUARE + 32)
#define KEY_SQR_H (KEY_DB_SQUARE + 33)
#define KEY_SQR_I (KEY_DB_SQUARE + 34)
#define KEY_SQR_J (KEY_DB_SQUARE + 35)
#define KEY_SQR_K (KEY_DB_SQUARE + 36)
#define KEY_SQR_L (KEY_DB_SQUARE + 37)
#define KEY_SQR_M (KEY_DB_SQUARE + 38)
#define KEY_SQR_N (KEY_DB_SQUARE + 39)
#define KEY_SQR_O (KEY_DB_SQUARE + 40)
#define KEY_SQR_P (KEY_DB_SQUARE + 41)
#define KEY_SQR_Q (KEY_DB_SQUARE + 42)
#define KEY_SQR_R (KEY_DB_SQUARE + 43)
#define KEY_SQR_S (KEY_DB_SQUARE + 44)
#define KEY_SQR_T (KEY_DB_SQUARE + 45)
#define KEY_SQR_U (KEY_DB_SQUARE + 46)
#define KEY_SQR_V (KEY_DB_SQUARE + 47)
#define KEY_SQR_W (KEY_DB_SQUARE + 48)
#define KEY_SQR_X (KEY_DB_SQUARE + 49)
#define KEY_SQR_Y (KEY_DB_SQUARE + 50)
#define KEY_SQR_Z (KEY_DB_SQUARE + 51)
#define KEY_SQR_PG_UP (KEY_DB_SQUARE + 52)
#define KEY_SQR_PG_DN (KEY_DB_SQUARE + 53)
#define KEY_SQR_LEFT (KEY_DB_SQUARE + 54)
#define KEY_SQR_RIGHT (KEY_DB_SQUARE + 55)
#define KEY_SQR_UP (KEY_DB_SQUARE + 56)
#define KEY_SQR_DN (KEY_DB_SQUARE + 57)
#define KEY_UNDEF (KEY_DB_SQUARE + 58)
#define KEY_E2BT3_END KEY_UNDEF

#endif