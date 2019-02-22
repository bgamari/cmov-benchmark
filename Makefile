PROGS=test_c test_c_opt test_cmov test_jump test_jump2

all: ${PROGS}

test_%: main.o fib_%.o
	g++ -o $@ $+

fib_c_opt.o : CXXFLAGS=-O

clean:
	rm ${PROGS} *.o -f

