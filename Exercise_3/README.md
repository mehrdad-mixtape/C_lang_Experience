# Makefile:
@ You can write some rules to build your code.

@ This file should has:

> name: *Makefile*

> path: current path where you write *.c file*

## CFLAGS = -... or - -...:
> You can set switches to C compiler.

> Ex: CFLAGS= -Wall -g

> `-Wall`: show all warnings

> `-g`: get debugging

> $ make ex1

## clean:
> You can write any commands to clean up your project, when you call this section, *make* goes and run all commands that you write.

> Ex: clean:

>					rm -rf EXECUTEABLE_FILE

> $ make clean

