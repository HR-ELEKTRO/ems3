UNAME := $(shell uname)

.PHONY: targets
ifeq ($(UNAME), Linux)
EXE :=
else ifeq ($(UNAME), Darwin)
EXE := .exe
else
EXE := .exe
endif

GCC_C_OPTIONS := -std=c18 -Wall -Wextra -pedantic-errors -g3 -O0

main$(EXE) : breuk.o main.o
	gcc breuk.o main.o -o main$(EXE)

breuk.o : breuk.c breuk.h
	gcc $(GCC_C_OPTIONS) -c breuk.c

main.o : main.c breuk.h
	gcc $(GCC_C_OPTIONS) -c main.c

.PHONY: clean
clean :
	rm breuk.o main.o main$(EXE)
