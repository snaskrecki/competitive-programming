#!/bin/bash

usage() {
  echo "Usage: $0 nofiles" 1>&2
}

exit_abnormal() {
  usage 
  exit 1
}

if [ $# -ne 1 ]; then
  exit_abnormal
fi

mkdir -p test/{input,exout,urout}

for (( i = 1; i <= $1; i++ )) ; do
  for prefix in input exout ; do
    > ./test/${prefix}/${prefix}0${i}.txt
  done
done
