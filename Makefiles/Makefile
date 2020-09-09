# Esto es un comentario
# @: target
# ^: todas las dependencias
# <: la primera dependencia

CXX = g++
CXXFLAGS = -O2 -g

all: fig.pdf

%.x: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

datos.txt: sumas.x
	./$< > $@

fig.pdf: plot.py datos.txt
	python3 $<

clean:
	rm -f a.out *.x datos.txt
