CC=g++
CFLAGS=-c -Wall -g
INCLUDES = -I../utils
LDFLAGS= -L../lib -lutils -lpthread
SOURCES=server_main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=Server

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	-cp $(EXECUTABLE) ../bin/

.cc.o:
	$(CC) $(INCLUDES) $(CFLAGS) $< -o $@

clean:
	-$(RM) $(OBJECTS)
	-$(RM) $(EXECUTABLE) ../bin/$(EXECUTABLE)
