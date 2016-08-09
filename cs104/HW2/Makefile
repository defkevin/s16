CC = g++
ALIST_SRCS = alist.cpp alist_test.cpp
ALIST_OBJ = $(ALIST_SRCS:.cpp=.o)

LLIST_SRCS = LListInt.cpp LListIntTest.cpp
LLIST_OBJ = $(LLIST_SRCS:.cpp=.o)

LLISTSTR_SRCS = LListString.cpp LListStringTest.cpp
LLISTSTR_OBJ = $(LLISTSTR_SRCS:.cpp=.o)

STACK_SRCS = stackint.cpp stackinttest.cpp
STACK_OBJ = $(STACK_SRCS:.cpp=.o)


all: alist_test llist_test stack_test laundry string_test

alist_test: $(ALIST_OBJ)
	$(CC) $(ALIST_OBJ) -o alist_test

llist_test: $(LLIST_OBJ)
	$(CC) $(LLIST_OBJ) -o llist_test

string_test: $(LLISTSTR_OBJ)
	$(CC) $(LLISTSTR_OBJ) -o string_test

stack_test: $(STACK_OBJ) LListInt.o
	$(CC) $(STACK_OBJ) LListInt.o -o stack_test

laundry: stackint.o llistint.o laundry.o
	$(CC) stackint.o llistint.o laundry.o -o laundry

.cpp.o:
	$(CC) -c $<

alist.o : alist.h
list.o : LListInt.h
stack.o : stackint.h
string.o : LListString.h

clean:
	rm -f *.o alist_test llist_test stack_test string_test *~
