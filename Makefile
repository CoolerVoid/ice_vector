CC=gcc
CFLAGS=-Wall -Wextra -O2 -fstack-protector-all -D_FORTIFY_SOURCE=2

all: 
	$(CC) -o bin_test/ice_vector_test src_test/main.c lib/ice_vector.c lib/mem_ops.c $(CFLAGS)

clean:
	rm -rf *.o bin_test/*
