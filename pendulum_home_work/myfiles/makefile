CC=gcc
CFLAGS=-I.
DEPS= ellint.h agm.h ode.h blas.h
OBJ= pendComp.o ellint.o agm.o ode.o blas.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lm

pendComp.exe: $(OBJ)
	$(CC) -o $@ $+ -lm

clean:
	$(RM) *.o *.exe a.out *.csv

scrub: clean
	$(RM) *.dat
