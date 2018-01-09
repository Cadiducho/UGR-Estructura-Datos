SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -g  -I$(INC) -c


all: $(BIN)/usopilas_max

documentacion:
	doxygen doc/doxys/Doxyfile

run:
	$(BIN)/usopilas_max
$(BIN)/usopilas_max: 
	$(CXX) -o $(BIN)/usopilas_max $(SRC)/usopilas_max.cpp

clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
