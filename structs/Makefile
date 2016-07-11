CC = g++
LDFLAGS =
SRCS = graph.cpp graph_test.cpp
OBJ = $(SRCS:.cpp=.o)
DEMOSRC = graph.cpp graph_test.cpp
DEMOOBJ = $(DEMOSRC:.cpp=.o)

all: graph_test graph

graph: $(DEMOOBJ)
	$(CC) $(DEMOOBJ) -o graph

graph_test: graph
	$(CC) $(OBJ) -o graph_test

.cpp.o:
	$(CC) -c $<

graph.o : graph.h

clean:
	rm -f *.o graph *~
