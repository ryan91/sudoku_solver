RM = rm

CC = gcc

CFLAGS = -Wall -std=c99 -O2

# INCLUDES = ...

# LFLAGS = ...

# LIBS = ...

SRCS = global.c readsudoku.c solver.c main.c

OBJS = $(SRCS:.c=.o)

MAIN = sudoku_solver

.PHONY: depend clean

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	-@$(RM) *.o *~ $(MAIN) 2>/dev/null || true

depend: $(SRCS)
	makedepend $(INCLUDES) $^


