# Brainfsck interpreter
## Introduction
The project is a simple brainfsck interpreter written in C.

It provides basic functionality of interpreting provided brainfsck files, along with
an in-console visualiser.

The main aim of this project was creating a simple, multi-OS C program and train
all-around programming skills. The project is small in scale, it might, possibly be
expanded in the future.

## Installation and compilation
The program should run on any operational system which supports the C language,
it has been tested on Windows 10 and the Ubuntu distribution of Linux.

Install the program by running `git clone` on this repository:
```shell
git clone https://github.com/kubapoke/brainfsck-interpreter
```
Subsequently, run:
```shell
cmake <project-directory-path>
cmake --build .
```
In your select build directory, where `<project-directory-path>` is 
the path to the directory in which `CMakeLists.txt` is stored.
This requires having `cmake` installed.

## Usage
```shell
./bf-interpreter [options]
```
Note, that the `-n` option is required.

## Program options
|       Name       | Symbol |                       Description                       | Takes argument | Optional | Default |
|:----------------:|:------:|:-------------------------------------------------------:|:--------------:|:--------:|:-------:|
|       Path       |   -n   |            Path to the appropriate .bf file             |       YES      |    NO    |    -    |
| Max instructions |   -i   | Maximum number of instructions in the provided .bf file |      YES       |    YES   |   2^15  |
|     Max cells    |   -c   |             Maximum number of working cells             |       YES      |    YES   |   2^15  |
|    Visual mode   |   -v   |     Launches program in [visual mode](#Visual-mode)     |       NO       |    YES   |   OFF   |

## Visual mode
If the `-v` flag is used, the program will enter visual mode. While the visual mode is active,
the program will display both the instructions and working cells as a row of characters,
with a `^` character pointing upwards at the command currently being handled, and the
working cell currently being pointed to by the cell counter. All non-printable and white
characters in the working cell area are replaced with spaces.

The program prints its current state after each operation, which results in a significant
loss of speed and a lot of clutter inside the console. It may be advised to
redirect the console output to a file if you want to avoid that. Moreover, if
the amount of commands is too large to fit in a single console line, the visualisation
won't look very well.

## Example usage

**Input**
```shell
./bf-interpreter -n ./bf-programs/hello-world.bf
```

**Output**
```shell
Hello world!
```
## References
- [Brainfsck description](https://en.wikipedia.org/wiki/Brainfuck)
