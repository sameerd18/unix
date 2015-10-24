CFLAGS:= -std=c11 -W -Wall -pedantic -Werror
SHELL:= /bin/bash

.PHONY: all
all: test

.PHONY: test

test:: true
	./true

test:: false
	! ./false

include $(wildcard *.mak)

.PHONY: clean
clean::
	$(RM) $$(<.gitignore)
