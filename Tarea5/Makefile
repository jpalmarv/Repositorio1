all: main-enclosedparticle.x

CXX=g++
OBJECTS=main-enclosedparticle.o enclosedparticle-simul.o
CXXFLAGS=-O2 -g -std=c++14

main-enclosedparticle.x: $(OBJECTS) particle.h
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o *.x *.txt
