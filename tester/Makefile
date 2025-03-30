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

show_only_errors :
	$(CC) $(CFLAGS) $(SRCS) -o test
	@2>&1 valgrind --leak-check=full --track-origins=yes ./test  | grep -E "errors from|heap|HEAP|open|Command|blocks" \
	| GREP_COLORS='mt=1;4;32' grep --color=always -E "HEAP SUMMARY|$$" \
	| GREP_COLORS='mt=1;4;31' grep --color=always -E "ERROR SUMMARY|$$" \
	| GREP_COLORS='mt=1;4;33' grep --color=always -E "FILE DESCRIPTORS|$$" \
	| GREP_COLORS='mt=1;4;36' grep --color=always -E "==.......==|$$" \
	| GREP_COLORS='mt=1;5;35' grep --color=always -E "All heap blocks were freed -- no leaks are possible|$$"
