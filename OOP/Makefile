CXX = g++

TARGET = main

__DIRNAME := $(abspath $(lastword $(dir $(MAKEFILE_LIST))))

MAIN_CPP = main.cpp
MAIN_OBJ = $(MAIN_CPP:.cpp=.o)



all: build run

build: $(MAIN_OBJ)
	@$(CXX) -Wall $(MAIN_OBJ) -o $(TARGET)

run:
	$(__DIRNAME)/$(TARGET)