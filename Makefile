PROGS=test_c test_cmov test_jump

all: ${PROGS}

test_%: main.o fib_%.o
	g++ -o $@ $+

fib.o : CXXFLAGS=-O

clean:
	rm ${PROGS} *.o -f
