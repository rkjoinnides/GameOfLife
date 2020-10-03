#name of the compiler
CXX = g++
#use the newest version of the compiler
CXXFLAGS = -std=c++0x 
#wall turns on all warnings
CXXFLAGS += -Wall
#pedantic-errors converts diagnostic warnings to errors
CXXFLAGS += -pedantic-errors
#used for debugging
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

#can place all of your objects to build here
#OBJS = main.o menu.o validateInt.o DoublyLinkedList.o Node.o
OBJS = main.o GameBoard.o TerminalRenderer.o

#place all .cpp files you want to build here
SRCS = main.cpp GameBoard.cpp TerminalRenderer.cpp

#put the headers here
HEADERS = GameBoard.hpp TerminalRenderer.hpp

#target: dependencies
#	rule to build
#

#variables are decalred using $() or &{}
main: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o main -lncurses

#this expands all the objects to depend on the sources
#-c compiles sources to object code
#@ builds all .o files from .cpp files
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o main