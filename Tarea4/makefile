all: fig.pdf

fig.pdf: datos-qr.txt datos-optimo.txt script.gp
	gnuplot script.gp

datos-qr.txt: run-qr.sh eigen-qr.x
	bash run-qr.sh

datos-optimo.txt: run-optimo.sh eigen-optimo.x
	bash run-optimo.sh

eigen-qr.x: eigen1.cpp
	g++ $< -o eigen-qr.x

eigen-optimo.x: eigen1.cpp
	g++ $< -O3 -o eigen-optimo.x
clean:
	rm -rf *.x a.out *.x.* *.pdf *.txt *.log
