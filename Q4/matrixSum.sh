#!/bin/bash

read -p "Enter the order of the matrices (rows columns): " m n

# Validate input
if [ $m -le 0 ] || [ $n -le 0 ]
then
    echo "Error: Matrix dimensions must be positive!"
    exit 1
fi

declare -A matrix1
declare -A matrix2
declare -A res

echo "Enter the elements of matrix1 ($m x $n):"
for ((i=0; i<m; i++))
do
    for ((j=0; j<n; j++))
    do
        echo -n "matrix1[$i][$j]: "
        read matrix1[$i,$j]
    done
done

echo "Enter the elements of matrix2 ($m x $n):"
for ((i=0; i<m; i++))
do
    for ((j=0; j<n; j++))
    do
        echo -n "matrix2[$i][$j]: "
        read matrix2[$i,$j]
    done
done

# Calculate matrix sum
for ((i=0; i<m; i++))
do
    for ((j=0; j<n; j++))
    do
        res[$i,$j]=$((matrix1[$i,$j]+matrix2[$i,$j]))
    done
done

echo ""
echo "Matrix 1:"
for ((i=0; i<m; i++))
do
    for ((j=0; j<n; j++))
    do
        echo -n "${matrix1[$i,$j]} "
    done
    echo
done

echo ""
echo "Matrix 2:"
for ((i=0; i<m; i++))
do
    for ((j=0; j<n; j++))
    do
        echo -n "${matrix2[$i,$j]} "
    done
    echo
done

echo ""
echo "Result Matrix (Sum):"
for ((i=0; i<m; i++))
do
    for ((j=0; j<n; j++))
    do
        echo -n "${res[$i,$j]} "
    done
    echo
done