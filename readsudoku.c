#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "readsudoku.h"

int readSudoku(const char* file_name, char** sudoku_array) {
    FILE* fp;
    char ch;
    unsigned int i = 0;
    unsigned int j = 0;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("The file %s does not exist\n", file_name);
        return 1;
    } else {
        while( (ch = fgetc(fp)) != EOF) {
            if (!(ch == 'x'     || ('1' <= ch && ch <= '9'))) {
                printf("Malformed Character: %c - Aborting read procedure\n", ch);
                return 1;
            }
            sudoku_array[j][i] = ch;
            if (i < 8) {
                ++i;
            } else {
                i = 0;
                ++j;
                ch = fgetc(fp);
                if (ch != '\n') {
                    printf("Expected line break - Aborting read procedure\n");
                    return 1;
                }
            }
        }
    }
    fclose(fp);
    return 0;
}

