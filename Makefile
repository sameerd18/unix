CFLAGS:= -std=c11 -W -Wall -pedantic -Werror -MMD
SHELL:= /bin/bash

.PHONY: all
all: test

cat: main.o cat.o
head: main.o head.o
tail: main.o tail.o

.PHONY: test

test:: true
	./true

test:: false
	! ./false

include $(wildcard *.mak)

include $(wildcard *.d)

.PHONY: clean
clean::
	$(RM) $$(<.gitignore)
