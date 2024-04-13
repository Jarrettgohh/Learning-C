# Learning-C
Repo to store C codes while learning and reinforcing knowledge of C lang!

# To run each `.c` file
>> Using the run.sh file
- Removes the need to constantly run the file with the `gcc` command, having to specify the output file path. Before executing the output file.

```
learning-c$ ./run.sh -f <path_to_file>.c
```

> Script usage input flags
> 
-[-f] Name of C file to compile and execute (using gcc)
-[-v] Enable verbosity
-[-s] Version of C standard to compile with
-[-m] Link with the <math.h> from the C standard library (using the -lm flag when invoking gcc)
-[-l] Optional implementation (.c files) to link


