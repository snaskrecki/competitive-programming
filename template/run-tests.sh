#!/bin/bash

usage() {
  echo "Usage: $0 exe indir yodir eodir" 1>&2
}

exit_abnormal() {                               
  usage
  exit 1
}

validate_args() {
  if ! [ -x "${prog}" ] ; then 
    echo "prog must be a executable"
    exit 1
  fi

  if ! [ -d "${indir}" ] ; then
    echo "indir must be a directory"
    exit 1
  fi

  if ! [ -d "${eodir}" ] ; then
    echo "eodir must be a directory"
    exit 1
  fi
}

if [ $# -ne 4 ] ; then
  exit_abnormal
fi

prog="$1"
indir="$2"
eodir="$3"
yodir="$4"

validate_args

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
  diff -q "${yofile}" "${eofile}"
done

