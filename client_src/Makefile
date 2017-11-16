CXXFLAGS=-c -Wall -std=c++11
INCLUDES = -I../utils
LDFLAGS= -L../lib -lutils
SOURCES=client_main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=Client

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@
	-cp $(EXECUTABLE) ../bin/

.cc.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -o $@

clean:
	-$(RM) $(OBJECTS)
	-$(RM) $(EXECUTABLE) ../bin/$(EXECUTABLE)
