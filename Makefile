CC := g++
CFLAGS := -Wall -g
TARGET := compiler

SRCS := $(wildcard *.cpp)

OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: clean $(TARGET)


$(TARGET): $(OBJS)
	$(CC) -o $@ $^


%.o: %.cpp
	$(CC) $(CFLAGS) -c $<


clean:
	rm -rf $(TARGET) *.o *.gch
	
.PHONY: all clean