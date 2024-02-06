#!/bin/bash

file=""
verbose=false
std="c17"


# the colon (:) operator in the getopts argument indicates whether or not the flag takes in an argument
while getopts 'f:vs:h' OPTION; do
  case "$OPTION" in
    f)
      file=$OPTARG
      ;;

    v)
      verbose=true
      ;;

    s)
      std=$OPTARG
      ;;

    h)
      printf "\n [-f] Name of C file to compile and execute (using gcc)"
      printf "\n [-v] Enable verbose"
      printf "\n [-s] Version of C standard"
      printf "\n\n"
      exit
      ;;
    ?)
      echo "script usage: "$0" -f ... -s ... -v ... (Run the file with the -h flag to view the help menu)]" >&2
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


if [ "$verbose" = true ]; then 
printf "\n################### Using standard C language version "$std" to compile... ###############################\n\n"
printf "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Creating .out file at $file_dir_exe_out..."
printf "\n\n#######################################################################################################\n\n"

fi

gcc -std="$std" "$file" -o "$file_dir_exe_out" # using `gcc` command to compile .c file

./"$file_dir_exe_out" # executing .out file created by gcc (similar to .exe on windows - .out is created on linux)