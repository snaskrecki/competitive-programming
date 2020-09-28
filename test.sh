#!/bin/bash

prog="$1"
test_dir="$2"

for file in ${test_dir}/input*.txt
do
    ./${prog} < ${file} | diff - ${file/input/output}
done
