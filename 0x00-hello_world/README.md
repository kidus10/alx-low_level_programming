# C - Hello-World

*Description or function of all the programs in this directory are listed below.*

* 0-preprocessor :-  a script that runs a C file through the `preprocessor` and save the result into another file.
  * The C file name is saved in the variable `$CFILE`
  * The output is saved in the file `c`

* 1-compiler :- a script that `compiles` a C file but does not link.
  * The C file name is saved in the variable `$CFILE`
  * The output file is named the same as the **C file**, but with the extension `.o` instead of `.c`

* 2-assembler :- a script that generates the `assembly code` of a C code and save it in an output file.
  * The C file name is saved in the variable `$CFILE`
  * The output file is named the same as the **C file**, but with the extension `.s` instead of `.c`

* 3-name :- a script that `compiles` a C file and creates an `executable` named `cisfun`.
  * The C file name is saved in the variable `$CFILE`

* 4-puts.c :- a C program that prints exactly `"Programming is like building a multilingual puzzle`, followed by a new line using only the function `puts`. The programs ends with the value `0`.

* 5-printf.c :- a C program that prints exactly `with proper grammar, but the outcome is a piece of art,`, followed by a new line using only the function `printf`. The program returns `0`.

* 6-size.c :- a C program that prints the `size` of various `types` on the computer it is compiled and run on. The program returns `0`.

* 100-intel :- a script that generates the `assembly code` (Intel syntax) of a C code and save it in an output file.
  * The C file name is saved in the variable `$CFILE`
  * The output file is named the same as the **C file**, but with the extension `.s` instead of `.c`

* 101-quote.c :- a C program that prints exactly `and that piece of art is useful" - Dora Korpar, 2015-10-19`, followed by a new line, to the `standard error`. The program returns `1`.

## Note

* The C file name called `main.c` is stored in the environment variable `CFILE` by using the below command.
```
export CFILE=main.c
```

* The content of the `main.c` file is:
```
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    return (0);
}
```
