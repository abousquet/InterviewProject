AR=ar
ARFLAGS=-cvq
CC=g++
CFLAGS=-c -Wall -fPIC
LDFLAGS= -shared
SOURCES=TcpClient.cc TcpServer.cc RequestQueue.cc TcpSocket.cc CommonUtils.cc
OBJECTS=$(SOURCES:.cc=.o)
SHAREDEXT=so
STATICEXT=a
LIBNAME=libutils
SHAREDLIBRARY=$(LIBNAME).$(SHAREDEXT)
STATICLIBRARY=$(LIBNAME).$(STATICEXT)
LIBDIR=../lib/
RM=-rm -f

help:
	@echo "Targets: "
	@echo " shared  - make a shared library and place it in lib"
	@echo " static  - make a static library and place it in lib"
	@echo " objects - make all object files"
	@echo " clean   - remove all libraries and object files"

shared: clean_static $(SOURCES) $(SHAREDLIBRARY)

static: clean_shared $(SOURCES) $(STATICLIBRARY)

objects: $(OBJECTS)

$(STATICLIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)
	-mkdir $(LIBDIR)
	-cp $(STATICLIBRARY) $(LIBDIR)

$(SHAREDLIBRARY): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	-mkdir $(LIBDIR)
	-cp $(SHAREDLIBRARY) $(LIBDIR)

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(LIBNAME).*
	$(RM) $(LIBDIR)$(LIBNAME).*

clean_shared:
	@$(RM) $(SHAREDLIBRARY)
	@$(RM) $(LIBDIR)$(SHAREDLIBRARY)
clean_static:
	@$(RM) $(STATICLIBRARY)
	@$(RM) $(LIBDIR)$(STATICLIBRARY)
