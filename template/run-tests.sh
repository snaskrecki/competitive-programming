#!/bin/bash

# no args must be equal 4
if [ $# -ne 4 ]; then
    printf "Usage:\n";
    printf "  directory\n";
    printf "  build/don't\n";
    printf "  make/cmake\n";
    printf "  clean/don't\n";
    exit 0
fi

dir=$1
build=$2
system=$3
clean=$4

# go to project directory
cd "${dir}"

# build executables if needed
if [ $build = 'build' ]
then
    if [ $system = 'make' ]
    then
        cd build
        make
        cd ..
    elif [ $system = 'cmake' ]
    then
        cd cmake-build-debug
        cmake ..
        make
        cd ..
    fi
fi

# set executable path
if [ $system = 'make' ]
then
    executable="./build/main"
elif [ $system = 'cmake' ]
then
    executable="./cmake-build-debug/main"
fi

# run tests
printf '\ninput files:\n\n'
for file in test/input/*
do
	input=$(basename -- "${file}")
	output="test/output/$(echo "${input}" | sed 's/in/out/g')"

    #echo $input

    myout="test/myout/$(echo "${input}" | sed 's/input/myout/g')"
    # don't need to create myout, next instruction does that already
    # touch "${myout}"
    "${executable}" <"${file}" >"${myout}"

    # short version:
	# "${executable}" < "${file}" | diff -s - test/output/"${output}"
    diff -qs "${myout}" "${output}"

    # clean myouts after the test
    if [ $clean = 'clean' ]
    then
        rm "${myout}"
    fi
done

# clean build files
if [ $clean = 'clean' ]
then
    if [ $system = 'make' ]
    then
        # remove everything that is not named Makefile
        find build/* -not -name 'Makefile' -and -not -name 'makefile' -delete
    elif [ $system = 'cmake' ]
    then
        rm -rf cmake-build-debug/*
    fi
fi

