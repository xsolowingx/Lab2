#Algumas variaveis sao usadas com significado especial:
#$@ nome do alvo (target)
#$^ lista com os nomes de todos os pre-requisitos sem duplicatas
#$< nome do primeiro pre-requisito
# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf
#variáveis de compilação.
CC = g++
CFLAGS = -W -Wall -pedantic -ansi -O0 -g -std=c++11 -I. -I$(INC_DIR)
#variáveis de diretórios.
INC_DIR = ./include
BIN_DIR = ./bin
SRC_DIR = ./src
OBJ_DIR = ./build
DOC_DIR = ./doc
#variáveis objetos.
OBJETO1 = $(OBJ_DIR)/questao1/Funcionario.o $(OBJ_DIR)/questao1/Data.o $(OBJ_DIR)/questao1/Empresa.o\
$(OBJ_DIR)/questao1/main1.o 
#$(OBJ_DIR)/questao1/instanciamento.o

#variáveis arquivos .h
ARQ_H1 = $(INC_DIR)/questao1/Data.h $(INC_DIR)/questao1/Funcionario.h $(INC_DIR)/questao1/Empresa.h
#$(INC_DIR)/questao1/instanciamento.h

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

questao1:	$(OBJETO1)
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "========s====="
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/questao1 
	@echo "+++ [Executavel questao1 criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/questao1/Funcionario.o:	$(SRC_DIR)/questao1/Funcionario.cpp $(ARQ_H1)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/Data.o:	$(SRC_DIR)/questao1/Data.cpp $(ARQ_H1)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/main1.o:	$(SRC_DIR)/questao1/main1.cpp $(ARQ_H1)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/Empresa.o:	$(SRC_DIR)/questao1/Empresa.cpp $(ARQ_H1)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/questao1/instanciamento.o:	$(SRC_DIR)/questao1/instanciamento.cpp $(ARQ_H1)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(BIN_DIR)/questao1
	$(RM) $(OBJ_DIR)/questao1/*.o
