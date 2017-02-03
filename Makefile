## Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = clang++-3.9
CC = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
# OPT= -O1
CXXVER=-std=
VER=c++14
CPPFLAGS = $(CXXVER)$(VER) -I.
#CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS = $(OPT) -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += $(CXXVER)$(VER)
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
# $< means (expand to prerequisites)
# $@ means (expand to target)
LDFLAGS = -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = sjc
# PROGS = spell.o dictionary.o word.o

all: $(PROGS)

DASM: $(wildcard *.o)
	objdump -d -l -M intel -S $< > $(d:.=o).dasm
#	objdump -d -l -M intel -S $< > $(d:.=o).dasm
test_input:
	./sjc test.json  
# Targets rely on implicit rules for compiling and linking
sjc: sjc.o json_encode.o json_decode.o

json_encode.o: json_encode.cpp json_encode.h json.h
json_decode.o: jsondecode.cpp jsondecode.h json.h


# Phony targets

.PHONY: all clean distclean

# Standard clean
clean:
	rm -f *.o *.d

distclean: clean
	rm -f *.d $(PROGS)

fullclean: distclean
	rm -f *.s

# Include the *.d files
SRC := $(wildcard *.cc)
-include $(SRC:.cc=.d)
SRC := $(wildcard *.cpp)
-include $(SRC:.cpp=.d)
