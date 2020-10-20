set log xy
f(x) = A*x**B
A=1.0e-7; B=3;
fit f(x) 'datos.txt' via A, B
g(x) = C*x**D
C=1.0e-3; D=4;
fit g(x) 'datos-optimo.txt' via C, D
set xlabel 'N'
set ylabel 'CPU time (s)'
set term pdf 
set out "fig.pdf"
plot 'datos.txt' w lp lw 4 t 'Datos', f(x) lw 5 t 'fit-Datos',  'datos-optimo.txt' w lp lw 4 t 'optimo', g(x) lw 5 t 'fit-optimo'
