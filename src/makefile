####################################### Diretórios #########################################
# Aqui estão listados os diretórios do projeto

# Nomes dos executáveis
PROJECT_EXE = ../bir

# Nomes dos diretórios
DIR_HEADERS = ../lib
DIR_SOURCES = ../src
DIR_OBJECTS = ../obj


########################################## FLAGS ###########################################
# Especifica o compilador, a versão do C++ e as flags utilizadas para compilar o código

CC = g++ -std=c++11
CFLAGS = -I$(DIR_HEADERS)
LIBS = -lm


########################## Listas com nomes dos arquivos de código ##########################
# Define o local dos arquivos de código e arquivos de cabeçalho de código

_HEADERS = CamadaEnlace.hpp CamadaFisica.hpp
HEADERS = $(patsubst %,$(DIR_HEADERS)/%,$(_HEADERS))

_OBJECTS = Simulador.o CamadaEnlace.o CamadaFisica.o
OBJECTS = $(patsubst %,$(DIR_OBJECTS)/%,$(_OBJECTS))



############################################ Make ############################################
# Aqui são definidas as regras para compilar o código gerando arquivos objetos e binários

# Gera arquivos objeto para todos os .cpp que estão localizados no mesmo diretório do makefile e em seguida compila
$(DIR_OBJECTS)/%.o: %.cpp $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

# Chama todos os arquivos objeto, gerando binários e criando o executável
$(PROJECT_EXE): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


# MiniTutorial
# all: library.cpp main.cpp
# $@ - Chama o nome da regra 			- all
# $< - Chama o primeiro pré-requisito 	- libray.cpp
# $^ - Chama todos os pré-requisitos 	- library.cpp main.cpp



################################## Outras Regras de Make ####################################
# Aqui estão listadas algumas regras úteis de make para facilitar o trabalho

# make bir
# Limpa a tela e executa automaticamente o software
bir:
	clear
	./$(PROJECT_EXE)


# make all
# Chama todas as regras de make
all: $(PROJECT_EXE) bir



########################################## Clean ###########################################
# Deleta alguns arquivos do projeto (binários, objetos, gcov e gcda)

.PHONY: clean

# make clean

clean:
	rm -f $(DIR_OBJECTS)/*.o *~ core $(INCDIR)/*~ *.gcda *.gcno *.gcov *.o ../obj/*.gcno ../obj/*.gcda $(PROJECT_EXE) $(DIR_OBJECTS)/*.