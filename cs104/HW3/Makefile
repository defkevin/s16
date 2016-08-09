CC = g++

LLISTSTR_SRCS = LListString.cpp LListStr_Test.cpp
LLISTSTR_OBJ = $(LLISTSTR_SRCS:.cpp=.o)

all: lliststr_test setstr_test

lliststr_test: $(LLISTSTR_OBJ)
	$(CC) $(LLISTSTR_OBJ) -o lliststr_test

setstr_test: SetStr.o LListStr_Test.o LListString.o
	$(CC) SetStr.o LListStr_Test.o LListString.o -o setstr_test

.cpp.o:
	$(CC) -c $<

lliststr.o : LListString.h
setstr.o : SetStr.h

clean:
	rm -f *.o lliststr_test setstr_test *~