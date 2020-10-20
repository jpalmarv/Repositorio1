for N in 1 2 10 100 200 500; do
    echo -n "$N  "
    ./eigen-optimo.x $N 2
done > datos-optimo.txt

