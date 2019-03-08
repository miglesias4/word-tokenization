execute: interface.o tokenizer.o history.o
    gcc interface.o tokenizer.o history.o -o execute

interface.o: interface.c
    gcc -c interface.c

tokenizer.o: tokenizer.c tokenizer.h
    gcc -c history.c

history.o: history.c history.h
    gcc -c history.c

clean:
    rm *.o execute