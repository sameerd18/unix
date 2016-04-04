CFLAGS:= -W -Wall -pedantic -MMD -save-temps -O2
SHELL:= /bin/bash

.PHONY: all
all: hello

hello: hello.o mylib.so
mylib.so: greet.o target.o

%.so: LDFLAGS+=-shared
%.so: CFLAGS+=-fPIC
%.so:
	$(LINK.o) $^ -o $@

.PHONY: clean
clean::
	$(RM) $$(<.gitignore)
