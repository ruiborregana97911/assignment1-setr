# Diretórios
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
DOC_DIR = doc

# Ficheiros
TARGET = apptest
SOURCES = $(SRC_DIR)/apptest.c $(SRC_DIR)/MyDLL.c
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
CFLAGS = -g -Wall -O3 -I$(INC_DIR)
LDLIBS =
CC = gcc

# Geração do executável
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Geração dos ficheiros objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar diretório obj se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpar compilação
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Geração da documentação com Doxygen
docs:
	doxygen Doxyfile

# Limpar a documentação
clean-docs:
	rm -rf $(DOC_DIR)

.PHONY: all clean docs clean-docs

