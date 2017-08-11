CFLAGS+= -lpthread -lm
LDFLAGS+= 
EXEC=Test
CHAC= .*.swp
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
CC=g++
SHAREFLAG+=-fPIC

Tests:
	$(CC) -c *.cc
	$(CC) *.o -o $(EXEC) $(CFLAGS)

.PHONY: clean
clean:
	@rm $(OBJECTS) 
	@rm $(EXEC)
	@rm $(CHAC)
