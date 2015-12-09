CC:=g++
FLAGS:= -std=c++11 
OBJ:= ary.o -DLinux

all: ary.o exa.e

ary.o: tools/ARY.cpp 
	$(CC) -c $(FLAGS) $< -o $@

exa.e: example.cpp 
	$(CC) $(FLAGS) $(OBJ) $< -o $@ 


clean:
	rm -f *.o *.e
