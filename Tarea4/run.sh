for N in 1 2 10 100 200 500; do
    echo -n "$N  "
    ./eigen.x $N 10
done > datos.txt
