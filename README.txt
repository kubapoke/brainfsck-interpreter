A simple brainfsck interpreter written in C.

The bf-compile.bat file can be used to compile the interpreter on Windows, using the gcc compiler.

USAGE:
After compiling the file into interpreter.exe:

.\interpreter.exe -n <path to the .bf file>

Should interpret the .bf file after the mandatory -n option.


OTHER OPTIONS:

-i <max number of instructions> - Limits or increases maximum number of instructions which can be contained in the .bf file (2^15 by default)

-c <max number of cells> - Limits or increases maximum number of workable cells

-v - The interpreter enters verbose mode, in which it displays current position in instruction and working arrays. Doesn't work great if either is too large

