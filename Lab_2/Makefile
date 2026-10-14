CXX = g++
CXXFLAGS = -std=c++23 -Wall
TARGET = calculator
LIB = lib_calculator.a
SRCS = calculator.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
LIB_OBJS = calculator.o

all: $(LIB) $(TARGET)

$(LIB): $(LIB_OBJS)
	ar rcs $@ $^

$(TARGET): $(OBJS) $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ main.o $(LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(LIB) $(TARGET)

.PHONY: all clean
