CFLAGS:= -W -Wall -pedantic -MMD -save-temps -O2
SHELL:= /bin/bash

.PHONY: all
all: hello

hello: hello.c mylib.a
mylib.a: mylib.a(greet.o target.o)

.PHONY: clean
clean::
	$(RM) $$(<.gitignore)
