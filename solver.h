#ifndef SOLVER_H_INCLUDED
#define SOLVER_H_INCLUDED

/**
 * Tries to solve a given Sudoku.
 *
 * @param sudoku The Sudoku grid represented as a matrix
 * @return 0 if the array could be solved. Else, 1.
 */
int solve_sudoku(char** sudoku);

#endif // SOLVER_H_INCLUDED
