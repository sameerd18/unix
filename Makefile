.PHONY: all
all: test

.PHONY: test

test:: true
	./true

test:: false
	! ./false

.PHONY: clean
clean::
	$(RM) true false
