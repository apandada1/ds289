CC=gcc
CFLAGS=-I.
DEPS= ellint.h agm.h
OBJ= ellint.o agm.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -lm

ellint.exe: $(OBJ)
	$(CC) -o $@ $+ -lm

clean:
	$(RM) *.o *.exe a.out

scrub: clean
	$(RM) *.dat
