/* main.c 
   Author Natalia Robertson */
#include <stdio.h>
#include "picture.h"

int main(void) {
    int pic[][COLS] = {
        {1, 1, 1, 1, 1},   
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };
    int nrows = sizeof(pic) / sizeof(pic[0]);

    print_picture(pic, nrows);
    printf("find 1 -> %d\n", find_code(pic, nrows, 1));
    printf("find 9 -> %d\n", find_code(pic, nrows, 9));

    set_cell(pic, nrows, 1, 2, 1);
    printf("after set_cell(1, 2, 1):\n");
    print_picture(pic, nrows);

    set_cell(pic, nrows, 9, 0, 1);
    printf("set_cell(9, 0, 1) ignored\n");
    print_picture(pic, nrows);

    print_picture(nullptr, nrows);
    printf("find_code(nullptr) -> %d\n", find_code(nullptr, nrows, 1));
    return 0;
}
