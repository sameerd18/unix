test:: tail
	./tail < /dev/null | diff /dev/null -

test:: tail
	./tail < TestExpected/FileWithOneChar.txt | diff TestExpected/FileWithOneChar.txt -

test:: tail
	./tail < TestExpected/FileForCatString.txt | diff TestExpected/FileForCatString.txt -

test:: tail
	./tail < TestExpected/FileWith11Lines.txt | diff TestExpected/FileWithLast10Lines.txt -
