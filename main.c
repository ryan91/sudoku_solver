#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "readsudoku.h"
#include "solver.h"

/**
 * This program tries to resolve a given Sudoku file.
 *
 * @param argc Argument count
 * @param argv Arguments
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: <solver> <sudoku file>\n");
        exit(EXIT_FAILURE);
    } else {
        int ret;

        // allocate matrix to read into
        char** sudoku_array = allocate_sudoku();

        // read input sudoku file
        ret = readSudoku(argv[1], sudoku_array);

        // abort if file is corrupt
        if (ret != 0) {
            printf("The read process failed - exiting\n");
            exit(EXIT_FAILURE);
        }

        // print input sudoku
        printf("<<INPUT  SUDOKU>>\n");
        print_sudoku(sudoku_array);
        printf("-----------------\n");

        // solve it
        ret = solve_sudoku(sudoku_array);

        // print output sudoku
        printf("<<OUTPUT SUDOKU>>\n");
        print_sudoku(sudoku_array);
        printf("-----------------\n");

        // print if the sudoku could be solved
        if (ret == 0)
            printf("The Sodoku was solved\n");
        else
            printf("The Sudoku is irresolvable\n");

        // free allocated matrix
        unallocate_sudoku(sudoku_array);

        exit(EXIT_SUCCESS);
    }
}

