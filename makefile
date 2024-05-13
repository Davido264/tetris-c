# The name of the source files
SOURCES = src/main.c src/tetromino.c src/render.c

# Flags for compilation (adding warnings are always good)
CFLAGS = -Wall -I include/ -I src/ -D NCURSES_WIDECHAR

# Flags for linking (none for the moment)
LDFLAGS =

# Libraries to link with (none for the moment)
LIBS = -lncurses

# This creates a list of object files from the source files
OBJECTS = $(SOURCES:src/%.c=build/%.o)

# The first target, this will be the default target if none is specified
# This target tells "make" to make the "all" target
default: all

# Having an "all" target is customary, so one could write "make all"
# It depends on the executable program
all: tetris-c

# This will link the executable from the object files
tetris-c: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o tetris-c $(LIBS)

# This is a target that will compile all needed source files into object files
# We don't need to specify a command or any rules, "make" will handle it automatically
build/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

# Target to clean up after us
clean:
	-rm -f tetris-c      # Remove the executable file
	-rm -f $(OBJECTS)  # Remove the object files

install: tetris-c
	mkdir -p $(out)/bin
	install -m 755 $(pname) $(out)/bin/$(pname)

build/main.o: src/main.c

