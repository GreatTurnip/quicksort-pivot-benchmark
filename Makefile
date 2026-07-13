CXX := g++
CXXFLAGS := -O3 -march=native -std=c++17 -Wall -Iinclude

HEADERS := $(wildcard include/*.h)
SRC := src/main.cpp
TARGET := build/quicksort_test

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)
	cd src && python3 graph_generator.py

clean:
	rm -f $(TARGET)

.PHONY: all run clean