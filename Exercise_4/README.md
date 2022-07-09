# Using debugger:

## GDB Tricks

Here’s a list of simple tricks you can do with GNU Debugger (GDB):

> gdb --args Normally, takes arguments you give it and assumes they are for itself. Using passes them to the program.

> thread apply all bt Dump a backtrace for all threads. It’s very useful.

> $ gdb --batch --ex r --ex bt --ex q --args Run the program so that if it bombs, you get a backtrace.

## GDB Quick Reference

back to the commands as you work. Here is a quick reference to the GDB commands that I used in the video so you can use them later in the book:

> <b>run

>		[args] Start your program with [args].

> <b>break

>		[file:]function Set a break point at [file:]function. You can also use b.

> <b>backtrace

>		Dump a backtrace of the current calling stack. Shorthand is bt.

> <b>print

>		expr Print the value of Shorthand is p.

> <b>continue

>		Continue running the program. Shorthand is c.

> <b>next

>		Next line, but step over function calls. Shorthand is n.

> <b>step

>		Next line, but step into function calls. Shorthand is s.

> <b>quit

>		Exit GDB.


> <b>help

>		List the types of commands. You can then get help on the class of command as well as the command.

> <b>cd, pwd, make

>		This is just like running these commands in your shell.

> <b>shell

>		Quickly start a shell so you can do other things.

> <b>clear

>		Clear a breakpoint.

> <b>info break, info watch

>		Show information about breakpoints and watch‐points.

> <b>attach pid

>		Attach to a running process so you can debug it.

> <b>detach

>		Detach from the process.

> <b>list

>		List out the next ten source lines. Add a to list the previous ten lines.
