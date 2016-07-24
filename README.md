# Sodoku Solver

## What does this?

This is a small solver for Sudoku riddles that I developed for funsies in my
spare time. It reads a Sudoku from a text file and solves it (if it can be
solved). The examples folder should demonstrate the format the Sudokus need to
be in for the solver to parse them properly. You'll never have to solve Sudokus
on your own! What a relief! ;)

## How does it solve Sudokus?

I've implemented a more or less brute-force algorithm. The solver starts in the
upper left corner of the grid and goes through the numbers from 1 to 9 until it
finds a number that does not provoke a conflict. Then it step (just like reading
a text) towards the lower right corner and starts the procedure again. If all
numbers up to 9 have resulted in conflicts for a certain square, the solver goes
back towards the left upper corner and tries other values. If the end of the
grid was reached without any conflicts, the Sudoku is solved. If the beginning
of the grid was reached and all numbers up to 9 resulted in conflicts, the
Sudoku cannot be solved.

## How to compile?

Simply enter `make`

## How to execute?

`./sudoku_solver <sudoku file>`
