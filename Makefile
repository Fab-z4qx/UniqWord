##
## MakeFile 
##
## Made by z4qx
##
##

CC = g++
RM = rm -f
LN =  ln -fs

CFLAGS =  -c -std=gnu++0x -s -O3 -DNDEBUG 
#LD_FLAGS = 

EXECUTABLE = zuniqw
PROGNAME =   bin/$@
#OBJECTS =    $(SOURCES:.cpp=.o)

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst src/%.cpp, obj/%.o, $(SOURCES))

all: $(SOURCES) $(EXECUTABLE) 

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ 

$(EXECUTABLE) : $(OBJECTS) 
	   $(CC) -o $(PROGNAME) $(OBJECTS)  
	   $(LN) $(PROGNAME) $(patsubst bin/%,%,$(PRGNAME))

#.cpp.o: 
#	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) obj/*o wuniq

