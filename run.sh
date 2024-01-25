#!/bin/bash

file=""
verbose=false

while getopts 'f:v' OPTION; do
  case "$OPTION" in
    f)
      file=$OPTARG
      ;;

    v)
      verbose=true
      ;;
    ?)
      echo "script usage: "$0" [-f name of file to compile and execute]" >&2
      exit 1
      ;;
  esac
done

shift "$(($OPTIND -1))"

pattern="\/*\w+\.c"
file_dir="$(sed -E "s/$pattern//" <<< $file)"

mkdir -p "out/$file_dir"

file_name_without_extension="${file%%.*}"
file_dir_exe_out="out/$file_name_without_extension.out"


if [ "$verbose" = true ]; 
then printf "\n###########################################\n\n Creating .out file at $file_dir_exe_out... \n\n###########################################\n\n"

fi


gcc "$file" -o "$file_dir_exe_out" # using `gcc` command to compile .c file
./"$file_dir_exe_out" # executing .out file created by gcc (similar to .exe on windows - .out is created on linux)