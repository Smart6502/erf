#!/bin/sh

make -C lib/ clean all
gcc -o erf erf.c -L lib/ -lerf
