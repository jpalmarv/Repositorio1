all: fig.pdf

fig.pdf: datos.txt datos-optimo.txt script.gp
	gnuplot script.gp

datos.txt: run.sh eigen.x
	bash run.sh

datos-optimo.txt: run-optimo.sh eigen-optimo.x
	bash run-optimo.sh

eigen.x: eigen1.cpp
	g++ $< -o eigen.x

eigen-optimo.x: eigen1.cpp
	g++ $< -O3 -o eigen-optimo.x
clean:
	rm -rf *.x *.x.* *.pdf *.txt *.log
