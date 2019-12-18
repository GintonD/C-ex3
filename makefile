
CC=gcc
FLAG=-Wall
AR=ar
fPIC=-fPIC
all: main_isort main_txtfind 

main_isort: isort.c  
	$(CC) $(FLAG) isort.c -g -o isort
main_txtfind: txtfind.c 
	$(CC) $(FLAG) txtfind.c -g -o txtfind

.PHONY:  isort txtfind clean all
clean:
	rm -f *.o *.a *.so isort txtfind
