SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

run:
	$(BIN)/prueba datos/timeline_movies.txt
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o
		$(CXX) -o $(BIN)/prueba $(OBJ)/pruebacronologia.o $(OBJ)/Fecha_Historica.o $(OBJ)/Cronologia.o

$(OBJ)/pruebacronologia.o : $(INC)/Cronologia.h $(INC)/Fecha_Historica.h $(SRC)/pruebacronologia.cpp
		$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/pruebacronologia.o $(SRC)/pruebacronologia.cpp

$(OBJ)/Cronologia.o : $(INC)/Cronologia.h $(INC)/Fecha_Historica.h $(SRC)/Cronologia.cpp
		$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Cronologia.o $(SRC)/Cronologia.cpp

$(OBJ)/Fecha_Historica.o : $(INC)/Fecha_Historica.h $(SRC)/Fecha_Historica.cpp
		$(CXX) $(CPPFLAGS) -I./$(INC) -c -o $(OBJ)/Fecha_Historica.o $(SRC)/Fecha_Historica.cpp


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
