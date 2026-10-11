CC = clang
CFLAGS = -Wall -Wextra -std=c17
TARGET = test_alu
SOURCES = alu.c test_alu.c

all: $(TARGET)

$(TARGET): $(SOURCES) alu.h
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)