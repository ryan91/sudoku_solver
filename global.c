#include <stdlib.h>
#include <stdio.h>
#include "global.h"

char** allocate_matrix(const unsigned int width, const unsigned int height) {
    char** array = (char**) malloc(width * sizeof(char*));
        for (int i = 0; i < 9; ++i)
            array[i] = (char*) malloc(height * sizeof(char));
    return array;
}

char** allocate_sudoku(void) {
    return allocate_matrix(9, 9);
}

void unallocate_matrix(char** matrix, const unsigned int width) {
    for (unsigned int i = 0; i < width; ++i)
        free(matrix[i]);
    free(matrix);
}

void unallocate_sudoku(char** sudoku) {
    unallocate_matrix(sudoku, 9);
}

void print_matrix(char** matrix, int width, int height) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_sudoku(char** sudoku) {
    print_matrix(sudoku, 9, 9);
}

void copy_sudoku(char** source, char** target) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            target[i][j] = source[i][j];
        }
    }
}
