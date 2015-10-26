test:: head
	./head < /dev/null | diff /dev/null -

test:: head
	./head < TestExpected/FileWithOneChar.txt | diff TestExpected/FileWithOneChar.txt -

test:: head
	./head < TestExpected/FileForCatString.txt | diff TestExpected/FileForCatString.txt -

test:: head
	./head < TestExpected/FileWith11Lines.txt | diff TestExpected/FileWith10Lines.txt -

test:: head
	./head TestExpected/FileForCatString.txt | diff TestExpected/FileForCatString.txt -

test:: head
	./head DoesNotExist.txt 2>/dev/null | diff /dev/null -

test:: head
	! ./head DoesNotExist.txt 2>/dev/null

test:: head
	./head DoesNotExist.txt 2>&1 | grep DoesNotExist.txt > /dev/null

test:: head
	./head TestExpected/FileForCatFile1.txt TestExpected/FileForCatFile2.txt | diff TestExpected/ConcatenatedFilesForCatFiles.txt -

test:: head
	./head TestExpected/FileWith11Lines.txt TestExpected/File2With11Lines.txt | diff TestExpected/ConcatenatedFilesForHeadFiles.txt -
