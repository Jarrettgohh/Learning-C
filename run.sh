#!/bin/bash

file_name=""

while getopts 'f:' OPTION; do
  case "$OPTION" in
    f)
      file_name=$OPTARG
      ;;
    ?)
      echo "script usage: "$0" [-f name of file to compile and execute]" >&2
      exit 1
      ;;
  esac
done

shift "$(($OPTIND -1))"

file_name_without_extension="${file_name%%.*}"
file_name_exe_out="$file_name_without_extension.out"

gcc "$file_name" -o "$file_name_exe_out" # using `gcc` command to compile .c file
./$file_name_exe_out # executing .out file created by gcc (similar to .exe on windows - .out is created on linux)