#include <stdio.h>

#include "global.h"
#include "solver.h"

// In this state we go forwards to find the next empty entry
#define STATE_STEP_FORWARD 0
// In this state we go backward after we found an irresolvable conflict
#define STATE_STEP_BACKWARD 1
// In this state we try to assign a value to the current square
#define STATE_SOLVE 2
// This state is reached when the Sudoku could not be solved
#define STATE_IRRESOLVABLE 3
// This state is reached when the Sudoku was solved
#define STATE_SOLVED 4

unsigned int tile(unsigned int index) {
    if (index <= 2) return 0;
    else if (index <= 5) return 3;
    else return 6;
}

unsigned int col_contains(char** arr, unsigned int x, unsigned int y) {
    const char number = arr[x][y];
    for (unsigned int i = 0; i < 9; ++i) {
        if (arr[x][i] == number && i != y)
            return 1;
    }
    return 0;
}

unsigned int row_contains(char** arr, unsigned int x, unsigned int y) {
    const char number = arr[x][y];
    for (unsigned int i = 0; i < 9; ++i) {
        if (arr[i][y] == number && i != x)
            return 1;
    }
    return 0;
}

unsigned int square_contains(char** arr, unsigned int x, unsigned int y) {
    const char number = arr[x][y];
    unsigned int x_start = tile(x);
    unsigned int y_start = tile(y);
    for (unsigned int i = x_start; i < x_start + 3; ++i)
        for (unsigned int j = y_start; j < y_start + 3; ++j)
            if (arr[i][j] == number && !(i == x && j == y)) return 1;
    return 0;
}

unsigned int sudoku_correct(char** arr, unsigned int x, unsigned int y) {
    return !(row_contains(arr, x, y) || col_contains(arr, x, y) || square_contains(arr, x, y));
}

int solve_sudoku(char** sudoku) {
    // create a copy of the original sudoku - replace 'x' with '0'
    char** copy = allocate_sudoku();
    copy_sudoku(sudoku, copy);
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            if (copy[i][j] == 'x')
                copy[i][j] = '0';


    unsigned int nx = 0;
    unsigned int ny = 0;

    unsigned int state = sudoku[nx][ny] == EMPTY_SQUARE ? STATE_SOLVE : STATE_STEP_FORWARD;

    while (1) {
        switch (state) {
            case STATE_SOLVE:
                if (copy[nx][ny] == '9') {
                    // reset current square and go back
                    copy[nx][ny] = '0';
                    state = STATE_STEP_BACKWARD;
                } else {
                    // assign a value and check if there is a conflict
                    ++copy[nx][ny];
                    if (sudoku_correct(copy, nx, ny)) {
                        state = STATE_STEP_FORWARD;
                    }
                }
                break;
            case STATE_STEP_FORWARD:
                if (EOS(nx, ny)) {
                    // the end of the sudoku was reached without a conflict
                    state = STATE_SOLVED;
                } else {
                    // go forward until a non-empty square was reached
                    INC_COORD(nx, ny)
                    if (sudoku[nx][ny] == EMPTY_SQUARE) state = STATE_SOLVE;
                }
                break;
            case STATE_STEP_BACKWARD:
                if (BOS(nx, ny)) {
                    // the beginning of the Sudoku was reached therefore it is irresolvable
                    state = STATE_IRRESOLVABLE;
                } else {
                    // go backward until a non-empty square was reached
                    DEC_COORD(nx, ny)
                    if (sudoku[nx][ny] == EMPTY_SQUARE) state = STATE_SOLVE;
                }
                break;
            case STATE_SOLVED:
                copy_sudoku(copy, sudoku);
                unallocate_sudoku(copy);
                return 0;
            case STATE_IRRESOLVABLE:
                copy_sudoku(copy, sudoku);
                unallocate_sudoku(copy);
                return 1;
        }
    }
}

