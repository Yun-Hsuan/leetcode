EXU:= test.e
CC:=g++
OBJ:= J.o
FLAGS:= -O3 -m64 -std=c++11 #-pg -Wall
all: $(OBJ) $(EXU)

$(OBJ): %.o: %.cpp
	$(CC) -c -I$(INC) $(FLAGS) $< -o $@
	
$(EXU): %.e: %.cpp
	$(CC) -I$(INC) -L$(LIB) $(FLAGS) $< -o $@ $(OBJ) 

leak_check:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./dqmc.e

run:
	./$(EXU)

run_hup:
	nohup ./$(EXU) &

.PHONY: clean cleanobj cleandata cleanall
clean:
	rm -f $(EXU) $(OBJ)
cleanobj:
	rm -rf $(OBJ)
cleandata:
	rm -rf Data *.out
cleanall: clean cleanobj cleandata
