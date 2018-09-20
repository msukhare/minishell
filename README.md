# minishell

## About minishell

* minishell is a simplified version of [sh](https://en.wikipedia.org/wiki/Bourne_shell).

* minishell doesn't handle [termcap](https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html), and [signals](https://www.tutorialspoint.com/unix/unix-signals-traps.htm).

* minishell has 5 [built-in](https://en.wikipedia.org/wiki/Shell_builtin) [cd](http://linuxcommand.org/lc3_man_pages/cdh.html), [echo](https://linux.die.net/man/1/echo), [setenv](http://man7.org/linux/man-pages/man3/setenv.3.html), [unsetenv](https://linux.die.net/man/3/unsetenv), [env](https://linux.die.net/man/1/env). They are not in [posix norm](https://en.wikipedia.org/wiki/POSIX)

* you can execute all binaries like in sh.

## What do you need to compile minishell ?

* gcc or clang

* make

* C library

* ar

## How to compile minishell ?

* Use `make` to compile `minishell`.

## Usage:

* `./minishell` or `env -i ./minishell`

## Rules of Makefile:

all: compile `libft.a`, `minishell`

clean: delete objects

fclean: call clean and delete `libft.a`, `minishell`

re: call fclean and all
