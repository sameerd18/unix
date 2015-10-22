.PHONY: all
all: test

.PHONY: test
test:: true
	./true

.PHONY: clean
clean::
	$(RM) true
