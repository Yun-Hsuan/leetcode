EXU:= test_cpp.e
CC:=g++
FLAGS:= -O3 -m64 -std=c++0x #-pg -Wall
OBJ := Block.o Matrix.o
all: $(OBJ) $(EXU)

$(OBJ): %.o: %.cpp
	$(CC) -c -I$(INC) $(FLAGS) $< -o $@
	
$(EXU): %.e: %.cpp
	$(CC) -I$(INC) -L$(LIB) $(FLAGS) $(OBJ) $< -o $@ 

leak_check:
	valgrind --leak-check=yes ./test_cpp.e

run:
	./$(EXU)

run_hup:
	nohup ./$(EXU) &

.PHONY: clean cleanobj cleanall
clean:
	rm -f *.e *.out
cleanobj:
	rm -rf $(OBJ)
cleanall: clean cleanobj cleandata
