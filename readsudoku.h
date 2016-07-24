
#ifndef READSUDOKU_H_INCLUDED
#define READSUDOKU_H_INCLUDED

/**
 * Reads a given Sudoku grid. This grid must be of the following form:
 * - Values are written without spaces side by side
 * - Each line must contain exactly 9 characters
 * - An empty slot is marked by the character 'x'
 * See "sudoku.txt" for an example
 *
 * @param file_name     The name of the Sodoku file to read from
 * @param sudoku_array  A Sudoku grid represented as a matrix write the file into
 * @return 0 if everything went fine, else 1
 */
int readSudoku(const char* file_name, char** sudoku_array);

#endif // READSUDOKU_H_INCLUDED
