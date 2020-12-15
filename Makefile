SRC:=$(wildcard *.c)
OBJ:=$(patsubst %.c, %.o, $(SRC))
output.e:$(OBJ)
	gcc -o $@ $(OBJ)	
clean:
	rm *.o *.exe
