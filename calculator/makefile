CC = g++
CFLAGS = -Wall -Wextra -std=c++11
TARGET = calculator

all: $(TARGET)

$(TARGET): main.cpp
    $(CC) $(CFLAGS) main.cpp -o $(TARGET)

clean:
    rm -f $(TARGET)

help:
    @echo "Usage: ./calculator -o <operation> <numbers>"
    @echo "Operation can be: sum, average, median"
    @echo "Example: ./calculator -o sum 1 2 3 4 5 6 7 8"
