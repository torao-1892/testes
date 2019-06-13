#!/bin/bash

for a in `seq 0 255`;
do
    for b in `seq 0 255`;
    do
        printf 'a%c%cb' $a $b > /dev/ttyUSB0;
        printf 'a%c%cb' $a $b
    done;
done;
