# Algorithms and simple programs

> Here are programs that were too small to get a separate repository

## Assembly_intro

### print.asm
Basic output handling

#### Compilation
To compile run:
```shell
$ nasm -f elf print.asm
$ gcc -m32 print.o -o print
```

## Algorithms
Algorithms build in c

### queue
Two way queue with two pointers to tail and head.

### sorts
Comparison of sort algorithms

### stack
Stack implementation using struct

### stack_on_array
Stack implementation using array

## Operating systems
All of the programs that use system features.

###fork and system call
Using fork it creates child process that waits for parent to send system call, when a system call arrives it sets the flag and prints message.
