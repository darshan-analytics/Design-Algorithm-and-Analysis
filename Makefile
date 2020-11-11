# Enables debug messages while compiling
CXX = g++

# Compile and Link flags, libraries

CFLAGS = -g -Wall 



PROGS= program1

all: $(PROGS) 

# Add all object files to be linked in sequence
program1: assignment1.o

	$(CXX) $(CFLAGS) -o program1 assignment1.o
assignment1.o: assignment1.cpp	
	$(CXX) $(CFLAGS) -c assignment1.cpp

clean:
	rm -f *.o *.d *~ output.text $(PROGS) 

