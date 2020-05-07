#!/bin/bash

usage() {
    echo "Usage: $0 prog indir yodir eodir" 1>&2
}

exit_abnormal() {                               
    usage
    exit 1
}

prog="$1"
indir="$2"
eodir=$3
yodir="$4"

if [ $# -lt 1 ] ; then
    prog=./main
fi

if [ $# -lt 2 ] ; then
    indir=./test/in/
fi

if [ $# -lt 3 ] ; then
    eodir=./test/eo/
fi

if [ $# -lt 4 ] ; then
    yodir=./test/yo/
fi

if [ $# -gt 4 ] ; then
    exit_abnormal
fi

if ! [ -x $prog ] ; then
    exit_abnormal
fi

if ! [ -d $indir ] ; then
    exit_abnormal
fi

if ! [ -d $eodir ] ; then
    exit_abnormal
fi

mkdir -p "${yodir}"

for infile in "${indir}"/* ; do
    infile_name="${infile##*/}"
    eofile_name="${infile_name/input/output}"
    yofile_name="${eofile_name}"

    eofile="${eodir}${eofile_name}"
    yofile="${yodir}${yofile_name}"

    "${prog}" <"${infile}" >"${yofile}"

    # short version:
    # "${prog}" < "${infile}" | diff -s - "${eofile}"
    diff -sq "${yofile}" "${eofile}"
done

