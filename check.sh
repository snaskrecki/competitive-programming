#!/bin/bash

if [ $# -gt 3 ]
then
    printf "Usage: ${0} [prog] [tests] [results]\n"
    exit 1
fi

prog="main"
if [ $# -gt 0 ]
then
    prog="$1"
fi

test_dir="tests"
if [ $# -gt 1 ]
then
    test_dir="$2"
fi

result_dir="results"
if [ $# -gt 2 ]
then
    result_dir="$3"
fi

make -B all

for input in $test_dir/*.in
do
    echo "test: $input" 
    result=$(echo $input | sed 's/\.in/\.res/')
    result=$(echo $result | sed 's/tests/results/')
    output=$(echo $input | sed 's/\.in/\.out/')
    ./$prog <$input >$result
    diff -q $result $output
done
