test:: echo
	./echo | diff TestExpected/EchoWithoutArg.txt -

test:: echo
	./echo hello | diff TestExpected/EchoWith1Arg.txt -

test:: echo
	./echo hello world | diff TestExpected/EchoWith2Args.txt -

test:: echo
	./echo hello world hi | diff TestExpected/EchoWith3Args.txt -
