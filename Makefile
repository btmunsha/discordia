include config.mk

all:

clean:
	rm -rf test *.o

install:

test: test.o popen2.o terminal.o
	${CC} ${CFLAGS} -o test test.o popen2.o
	./test

test.o: test.c
	${CC} ${CFLAGS} -c test.c

popen2.o: popen2.c
	${CC} ${CFLAGS} -c popen2.c

terminal.o: terminal.c
	${CC} ${CFLAGS} -c terminal.c
