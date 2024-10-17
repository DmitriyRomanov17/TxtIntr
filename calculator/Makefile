CC = g++
CFLAGS = -Wall -Wextra -std=c++11
TARGET = calculator.o

all: $(TARGET)

$(TARGET): calculator.cpp
	$(CC) $(CFLAGS) calculator.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

help:
	@echo "Usage: ./calculator.o -o <operation> <numbers>"
	@echo "Operation can be: sum, average, median"
	@echo "Example: ./calculator.o -o sum 1 2 3 4 5 6 7 8"
