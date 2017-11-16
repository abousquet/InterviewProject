CXXFLAGS=-c -Wall -g -std=c++11
INCLUDES = -I../utils
LDFLAGS= -L../lib -lutils -lpthread
SOURCES=server_main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=Server

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@
	-cp $(EXECUTABLE) ../bin/

.cc.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@

clean:
	-$(RM) $(OBJECTS)
	-$(RM) $(EXECUTABLE) ../bin/$(EXECUTABLE)
