default:*.c *.h
	mkdir -p bin
	cc -o bin/test_the_tests spec_tests.c spec.c
	./bin/test_the_tests
