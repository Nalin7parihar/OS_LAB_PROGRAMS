#!/bin/bash

echo -n "Enter the number of elements: "
read n

# Validate input
if [ $n -le 0 ]
then
    echo "Error: Number of elements must be positive!"
    exit 1
fi

echo -n "Enter $n elements: "

for ((i=0; i<n; i++))
do
    read numbers[$i]
done

largest=${numbers[0]}

for num in ${numbers[@]}
do
    if [ $num -gt $largest ]
    then
        largest=$num
    fi
done

echo "The largest number is: $largest"