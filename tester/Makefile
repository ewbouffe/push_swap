# Makefile du repo test

SRCS = BFPRT_main.c BFPRT_pivotfinder.c BFPRT_targetfinder.c BFPRT_utils.c BFPRTtestmain.c libft_utils.c

OBJ = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 

HEADER = clean_test_header.h

test : 
	$(CC) $(CFLAGS) $(SRCS) -o test && ./test

testv :
	$(CC) $(CFLAGS) $(SRCS) -o test && valgrind --leak-check=full --track-origins=yes ./test
