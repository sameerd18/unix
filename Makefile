CFLAGS:= -std=c11 -W -Wall -pedantic -Werror
SHELL:= /bin/bash

.PHONY: all
all: test

.PHONY: test

test:: true
	./true

test:: false
	! ./false

test:: echo
	./echo | diff TestExpected/EchoWithoutArg.txt -

test:: echo
	./echo hello | diff TestExpected/EchoWith1Arg.txt -

test:: echo
	./echo hello world | diff TestExpected/EchoWith2Args.txt -

test:: echo
	./echo hello world hi | diff TestExpected/EchoWith3Args.txt -

test:: cat
	./cat < /dev/null | diff /dev/null -

test:: cat
	./cat < TestExpected/FileForCat.txt | diff TestExpected/FileForCat.txt -

test:: cat
	./cat < TestExpected/FileForCatString.txt | diff TestExpected/FileForCatString.txt -

test:: cat
	./cat TestExpected/FileForCatString.txt | diff TestExpected/FileForCatString.txt -

test:: cat
	./cat DoesNotExist.txt 2>/dev/null | diff /dev/null -

test:: cat
	! ./cat DoesNotExist.txt 2>/dev/null

test:: cat
	./cat DoesNotExist.txt 2>&1 | grep DoesNotExist.txt > /dev/null

.PHONY: clean
clean::
	$(RM) $$(<.gitignore)
