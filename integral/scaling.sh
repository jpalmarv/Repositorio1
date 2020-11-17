echo "Starting strong scaling with system size: 1000000"
    for NTH in 1 2 3 4 5 6 7 8; do
	echo -n "$NTH  ";
	./a.out $NS $NTH | head -n 1;
    done > scaling-$NS.txt
    
    echo "Computing parallel metrics from file scaling-$NS.txt ..."
    awk 'BEGIN {TS=1.0;} { if(NR==1) TS=$2;  print $1, $2, TS/$2, TS/$2/$1}' scaling-$NS.txt > metrics-$NS.txt
    echo "Metrics saved to: metrics-$NS.txt"
    echo "Done"

    while IFS= read -r line
do
  echo "$line"
done < metrics-.txt
