/* picture.c 
   Author: Natalia */
#include <stdio.h>
#include "picture.h"

static const char *glyph_for(int code) {
    if (code == 0) {
        return ".";
    }
    if (code == 1) {
        return "#";
    }
    return "?";
}

void print_picture(const int pic[][COLS], int nrows) {
    if (pic == nullptr || nrows <= 0) {
        return;
    }
    for (int r = 0; r < nrows; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%s", glyph_for(pic[r][c]));
        }
        printf("\n");
    }
}

int find_code(const int pic[][COLS], int nrows, int target) {
    if (pic == nullptr || nrows <= 0) {
        return -1;
    }
    for (int r = 0; r < nrows; r++) {
        for (int c = 0; c < COLS; c++) {
            if (pic[r][c] == target) {
                return r * COLS + c;
            }
        }
    }
    return -1;
}

void set_cell(int pic[][COLS], int nrows, int row, int col, int value) {
    if (pic == nullptr || nrows <= 0) {
        return;
    }
    if (row < 0 || row >= nrows || col < 0 || col >= COLS) {
        return;
    }
    pic[row][col] = value;
}
