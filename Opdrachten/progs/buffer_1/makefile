UNAME := $(shell uname)

.PHONY: targets
ifeq ($(UNAME), Linux)
EXE :=
else ifeq ($(UNAME), Darwin)
EXE := .exe
else
EXE := .exe
endif

LIBS := -lpthread
GCC_C_OPTIONS := -std=c18 -Wall -Wextra -pedantic-errors -g3 -O0

targets: demo$(EXE) test$(EXE)

demo$(EXE) : buffer.o demo.o
	gcc buffer.o demo.o $(LIBS) -o demo$(EXE)

test$(EXE) : buffer.o test.o
	gcc buffer.o test.o -o test$(EXE)

buffer.o : buffer.c buffer.h
	gcc $(GCC_C_OPTIONS) -c buffer.c

demo.o : demo.c buffer.h
	gcc $(GCC_C_OPTIONS) -c demo.c

test.o : test.c buffer.h
	gcc $(GCC_C_OPTIONS) -c test.c

.PHONY: clean
clean :
	rm buffer.o demo.o test.o demo$(EXE) test$(EXE)
