CC=gcc
DEPS=ellint.h agm.h ode.h blas.h
OBJ=final.o ellint.o agm.o ode.o blas.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lm

final.exe: $(OBJ)
	$(CC) -o $@ $+ -lm

clean:
	$(RM) *.o *.exe a.out

scrub: clean
	$(RM) *.dat
