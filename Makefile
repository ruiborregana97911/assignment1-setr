#Makefile
TARGET= apptest
OBJECTS= apptest.o MyDLL.o
CFLAGS= -g -Wall -O3
LDLIBS=
CC= gcc

all: $(TARGET)

#Generate apptest
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

#Generate Object Files
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(TARGET)
