#!/bin/bash

echo "Enter low value: "
read low
echo "Enter high value: "
read high

echo -n "Prime Numbers: "

for ((n=low; n<=high; n++))
do
    isPrime=1
    
    # Handle special cases
    if [ $n -lt 2 ]
    then
        isPrime=0
    elif [ $n -eq 2 ]
    then
        isPrime=1
    elif [ $((n%2)) -eq 0 ]
    then
        isPrime=0
    else
        # Check for odd divisors up to sqrt(n)
        for ((i=3; i*i<=n; i+=2))
        do
            if [ $((n%i)) -eq 0 ]
            then
                isPrime=0
                break
            fi
        done
    fi
    
    if [ $isPrime -eq 1 ]
    then
        echo -n "$n "
    fi
done

echo ""