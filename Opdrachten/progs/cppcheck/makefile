UNAME := $(shell uname)

.PHONY: targets
ifeq ($(UNAME), Linux)
EXE :=
LIBS := -lpthread
else ifeq ($(UNAME), Darwin)
EXE :=
LIBS := -lpthread
else
EXE := exe
LIBS := 
endif

target = main
sources := $(wildcard *.c)
objects := $(sources:%.c=%.o)
debug-objects = $(objects:%.o=%-debug.o)

$(target)$(EXE) : $(objects)
	gcc $(objects) $(LIBS) -o $@

%.o : %.c 
	gcc -std=c18 -Wall -Wextra -pedantic-errors -c $<

$(target)-debug$(EXE) :  $(debug-objects)
	gcc $(debug-objects) -o $@

%-debug.o : %.c
	gcc -std=c18 -Wall -Wextra -pedantic-errors -g3 -c -O0 -o $@ $<

.PHONY: clean debug

clean:
	rm -f *.o $(target)$(EXE) $(target)-debug$(EXE) *.stackdump

debug: $(target)-debug$(EXE)