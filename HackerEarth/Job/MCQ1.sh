#!/bin/bash

x=-f1
y=-f2
z="${4:-,}"
echo "${z}"
for arg in "$@xyz"
do
index=$(echo $arg | cut -f1 -d=)
val=$(echo $arg | cut -f2 -d=)
case $index in
X) x=$value;;
Y) y=$value;;
*)
((ans=x+y))
echo "$ans"
esac
done

error