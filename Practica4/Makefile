INCLUDE = include
LIB = lib
OBJ = obj
SRC = src
BIN = bin
DOC = doc
CXX = g++ -Wall -std=c++11 -I./$(INCLUDE) -DNDEBUG

all: $(BIN)/pruebaCronologia $(BIN)/unionCronologia $(BIN)/estadisticaEventos $(BIN)/filtradoPalabra $(BIN)/filtradoIntervalo

$(BIN)/pruebaCronologia : 
	$(CXX) -o $(BIN)/pruebaCronologia $(SRC)/pruebaCronologia.cpp

$(BIN)/unionCronologia : 
	$(CXX) -o $(BIN)/unionCronologia $(SRC)/unionCronologia.cpp
	
$(BIN)/estadisticaEventos : 
	$(CXX) -o $(BIN)/estadisticaEventos $(SRC)/estadisticaEventos.cpp
	
$(BIN)/filtradoPalabra : 
	$(CXX) -o $(BIN)/filtradoPalabra $(SRC)/filtradoPalabra.cpp
	
$(BIN)/filtradoIntervalo : 
	$(CXX) -o $(BIN)/filtradoIntervalo $(SRC)/filtradoIntervalo.cpp
	

docs:
	doxygen $(DOC)/doxys/Doxyfile
	
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
