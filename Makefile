# Nome do executável final
TARGET_BASE = main

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c17

# Diretórios do projeto
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Detecção do Sistema Operacional
ifeq ($(OS),Windows_NT)
    TARGET = $(BIN_DIR)/$(TARGET_BASE).exe
    MKDIR = mkdir -p $(1)
    RM = rm -rf $(1)
else
    TARGET = $(BIN_DIR)/$(TARGET_BASE)
    MKDIR = mkdir -p $(1)
    RM = rm -rf $(1)
endif

# Encontra todos os arquivos .c dentro da pasta src
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Regra principal
all: $(BIN_DIR) $(TARGET)

# Linkagem: Cria o executável unindo os objetos
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação: Cria cada arquivo .o a partir do .c correspondente
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criação das pastas usando a macro dinâmica configurada pelo OS
$(OBJ_DIR):
	@$(call MKDIR, $(OBJ_DIR))

$(BIN_DIR):
	@$(call MKDIR, $(BIN_DIR))

# Limpeza multiplataforma
clean:
	@$(call RM, $(OBJ_DIR))
	@$(call RM, $(BIN_DIR))

.PHONY: all clean
