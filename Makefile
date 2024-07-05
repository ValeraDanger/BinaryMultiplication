CC = gcc
CFLAGS = -Wall -g

# Имена выходных файлов
TARGET = bin_mult_test
BIN_MODULE = libmult.a 

# Список объектных файлов
OBJECTS = BinMult.o Source.o

all: $(TARGET)

# Правило для сборки исполняемого файла тестов
$(TARGET): $(OBJECTS) $(BIN_MODULE)
	$(CC) $(CFLAGS) $(OBJECTS) $(BIN_MODULE) -o $@

# Правило для сборки объектного файла BinMult.o
BinMult.o: BinMult.c BinMult.h
	$(CC) $(CFLAGS) -c BinMult.c -o $@

# Правило для сборки объектного файла тестов
Source.o: Source.c BinMult.h
	$(CC) $(CFLAGS) -c Source.c -o $@

# Правило для сборки статической библиотеки
$(BIN_MODULE): BinMult.o
	ar rcs $(BIN_MODULE) BinMult.o

clean:
	rm -f $(TARGET) *.o *.a
