#UNI10_ROOT := where you install uni10
PYINC := /usr/include/python2.7 
INC := $(UNI10_ROOT)/include
LIB := $(UNI10_ROOT)/lib
CC:=gcc
FLAGS:=-m64 -fPIC
#OBJ := ioData.o 
#all: ioData.o main.e 

#ioData.o: ioData.cpp
#	$(CC) $(FLAGS) -c -I$(INC) $< -o $@

main.e: main.c
	$(CC) $(FLAGS) $< -o $@ $(OBJ)

clean:
	rm -f *.o *.e
