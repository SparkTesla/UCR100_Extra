#!/bin/sh

list=(40 56 2 7 290 5 10)
size=${#list[@]}
size=$(($size-1))

echo ${list[*]}

for index1 in `seq 0 $size`; do
		for index2 in `seq 0 $size`; do
				if [ ${list[index2]} -ge ${list[index1]} ]; then
						temp=${list[$index2]}
						list[$index2]=${list[$index1]}
						list[$index1]=$temp
				fi
		done
done

echo ${list[*]}
