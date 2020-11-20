for NTH in 1 2 3 4 5 6 7 8; do
        echo -n "$NTH  ";
         mpirun -oversubscribe -np $NTH ./a.out;
    done > scaling.txt

    echo "Computing parallel metrics from file scaling.txt ..."
    awk 'BEGIN {TS=1.0;} { if(NR==1) TS=$2;  print $1, $2, TS/$2, TS/$2/$1}' scaling.txt > metrics.txt
    echo "Metrics saved to: metrics.txt"
done
echo "Done"
