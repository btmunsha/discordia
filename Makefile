include config.mk

all:

clean:
	rm -rf test *.o

install:

test: test.o popen2.o
	${CC} ${CFLAGS} -o test test.o popen2.o
	./test

test.o: test.c
	${CC} ${CFLAGS} -c test.c

popen2.o: popen2.c
	${CC} ${CFLAGS} -c popen2.c
