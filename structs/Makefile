CC = g++
GRAPH_SRCS = graph.cpp graph_test.cpp
GRAPH_OBJ = $(GRAPH_SRCS:.cpp=.o)

EXPRESSION_TREE_SRCS = expression_tree.cpp expression_tree_test.cpp
EXPRESSION_TREE_OBJ = $(EXPRESSION_TREE_SRCS:.cpp=.o)

all: graph_test expression_tree_test

graph_test: $(GRAPH_OBJ)
	$(CC) $(GRAPH_OBJ) -o graph_test

expression_tree_test: $(EXPRESSION_TREE_OBJ)
	$(CC) $(EXPRESSION_TREE_OBJ) -o expression_tree_test

.cpp.o:
	$(CC) -c $<

graph.o : graph.h
expression_tree.o : expression_tree.h

clean:
	rm -f *.o graph_test expression_tree_test *~