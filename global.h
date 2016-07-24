#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

/**
 * Placeholder for an unknown slot in the Sudoku
 */
#define EMPTY_SQUARE 'x'

/**
 * Increments x and y coordinate to properly traverse through a Sudoku grid
 */
#define INC_COORD(x,y) if (y < 8) ++y; else {y = 0; ++x;}

/**
 * Decrements x and y coordinate to properly traverse through a Sudoku grid
 */
#define DEC_COORD(x,y) if (y > 0) --y; else {y = 8; --x;}

/**
 * Beginning of Sudoku
 */
#define BOS(x,y) (x == 0 && y == 0)

/**
 * End of Sudoku
 */
#define EOS(x,y) (x == 8 && y == 8)

/**
 * Allocates memory for a matrix
 *
 * @param width     The width of the matrix
 * @param height    The height of the matrix
 * @return The created matrix
 */
char** allocate_matrix(const unsigned int width, const unsigned int height);

/**
 * Allocates memory for a Sudoku grid
 *
 * @return A Sodoku grid (9x9 squares)
 */
char** allocate_sudoku(void);

/**
 * Unallocates memory for an allocated matrix
 *
 * @param matrix    The matrix to unallocate
 * @param width     The width of the matrix (the outer size)
 */
void unallocate_matrix(char** matrix, const unsigned int width);

/**
 * Frees an allocated Sudoku matrix
 *
 * @param sudoku The Sudoku grid to unallocate
 */
void unallocate_sudoku(char** sudoku);

/**
 * Prints a given matrix to stdout
 *
 * @param matrix    The matrix to print
 * @param width     The width of the matrix
 * @param height    The height of the matrix
 */
void print_matrix(char** matrix, int width, int height);

/**
 * Prints a given Sudoku grid
 *
 * @param sudoku The Sudoku grid to print
 */
void print_sudoku(char** sudoku);

/**
 * Copies a given Sudoku grid
 *
 * @param source The source to read from
 * @param target The target to copy to
 */
void copy_sudoku(char** source, char** target);




#endif // GLOBAL_H_INCLUDED
