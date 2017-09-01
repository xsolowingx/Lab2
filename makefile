#Algumas variáveis são usadas com um significiado.
#$@ nome do alvo.
#$^ lista todos os pré-requisitos sem duplicatas.
#$< nome do primeiro pré-requisito.
#variáveis de compilação.
CC = g++
CFLAGS = -W -Wall -pedantic -ansi -O0 -g -std=c++11 -I. -I$(INC_DIR)
#variáveis de diretórios.
INC_DIR = ./include
BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./build
#variáveis objetos.
OBJETO1 = $(SRC_DIR)/questao1/main1.cpp $(SRC_DIR)/questao1/funcionario.cpp \
$(SRC_DIR)/questao1/data.cpp $(SRC_DIR)/questao1/empresa.cpp $(SRC_DIR)/questao1/start.cpp\
$(SRC_DIR)/questao1/criarfuncionario.cpp $(SRC_DIR)/questao1/criarempresa.cpp

#variáveis para os arquivos .h
ARQ_H1 = $(INC_DIR)/questao1/data.h $(INC_DIR)/questao1/funcionario.h $(INC_DIR)/questao1/empresa.h

all:	questao1 questao2

questao1:	$(OBJETO1)