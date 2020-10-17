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

for file in ${test_dir}/input*.txt
do
    result=${file##*/}
    result=${result_dir}/${result/input/result}
    ./${prog} < ${file} | tee ${result} | diff -q - ${file/input/output}
done
