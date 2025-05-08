EXT_PATH = ../swtools/_LIB/SDL3-3.2.8/x86_64-w64-mingw32
DLLS = $(EXT_PATH)/bin/SDL3.dll
BUILDDIR = .

CC = gcc
INCLPATH = \
	-I $(IF_PATH) \
	-I $(LIB_PATH) \
	-I $(EXT_PATH)/include
	
override CFLAGS += $(INCLPATH) -O2
particle_SOURCES = main.c

particle_HEADERS =

particle_LIBS = \
	-lmingw32 \
	-lcomdlg32 \
	-mwindows \
	$(EXT_PATH)/lib/libSDL3.dll.a

particle_OBJECTS = $(particle_SOURCES:.c=.o)
particle_BIN = $(BUILDDIR)/particle.exe

all: particle
clean:
	rm -rf $(particle_BIN) $(BUILDDIR) $(particle_OBJECTS)
builddir:
	@[ -d $(BUILDDIR) ] || mkdir $(BUILDDIR)

ifneq ($(INSTALL_PATH),)
install:
	mkdir -p $(INSTALL_PATH)/particle
	cp $(DLLS) $(INSTALL_PATH)/particle
	cp -rf ./images/* $(INSTALL_PATH)/particle
	cp $(particle_BIN) $(INSTALL_PATH)/particle
endif

particle: builddir $(particle_BIN)
	@echo "=== particle is ready ==="
$(particle_BIN): $(particle_OBJECTS) $(particle_HEADERS) 
	$(CC) $(CFLAGS) -o $@ $(particle_OBJECTS) $(particle_LIBS)

.PHONY: all clean particle builddir
