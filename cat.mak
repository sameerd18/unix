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

test:: cat
	./cat TestExpected/FileForCatFile1.txt TestExpected/FileForCatFile2.txt | diff TestExpected/ConcatenatedFilesForCatFiles.txt -
