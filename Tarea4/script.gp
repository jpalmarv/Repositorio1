set log xy
f(x) = A*x**B
A=1.0e-2; B=3;
fit f(x) 'datos-qr.txt' via A, B
g(x) = A*x**B
A=1.0e-3; B=4;
fit g(x) 'datos-optimo.txt' via A, B
set xlabel 'N'
set ylabel 'CPU time (s)'
set term pdf 
set out "fig.pdf"
plot f(x) lw 5 t 'fit-qr', 'datos-qr.txt' w lp lw 4 t 'qr', 'datos-optimo.txt' w lp lw 4 t 'optimo', g(x) lw 5 t 'fit-optimo'
