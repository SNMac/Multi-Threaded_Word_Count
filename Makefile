CXX=g++
CXXFLAGS=-std=c++17
OBJS=main.o dirSearch.o producer.o consumer.o

ifeq ($(OS), Windows_NT)
	TARGET=2022-os-hw2.exe
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		TARGET=2022-os-hw2.out
	endif
	ifeq ($(UNAME_S), Darwin)
		TARGET=2022-os-hw2
	endif
endif

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $(OBJS)

main.o : main.h main.cpp
dirSearch.o : main.h dirSearch.cpp
producer.o : main.h producer.cpp
consumer.o : main.h consumer.cpp

clean :
	rm -f *.o $(TARGET)