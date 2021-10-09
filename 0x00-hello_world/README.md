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

## Notes
Some important resources and tips.

### Betty linter

To run the Betty linter just with command `betty <filename>`:

* Go to the [Betty](https://github.com/holbertonschool/Betty) repository
* Clone the [repository](https://github.com/holbertonschool/Betty) to your local machine
* `cd` into the Betty directory
* Install the linter with `sudo ./install.sh`
* `emacs` or `vi` a new file called `betty`, and `copy` the script below:

```
#!/bin/bash
# Simply a wrapper script to keep you from having to use betty-style
# and betty-doc separately on every item.
# Originally by Tim Britton (@wintermanc3r), multiargument added by
# Larry Madeo (@hillmonkey)

BIN_PATH="/usr/local/bin"
BETTY_STYLE="betty-style"
BETTY_DOC="betty-doc"

if [ "$#" = "0" ]; then
    echo "No arguments passed."
    exit 1
fi

for argument in "$@" ; do
    echo -e "\n========== $argument =========="
    ${BIN_PATH}/${BETTY_STYLE} "$argument"
    ${BIN_PATH}/${BETTY_DOC} "$argument"
done
```
* Once saved, exit file and `change permissions` to apply to all users with: `chmod a+x betty`
* `Move` the `betty` file into `/bin/` directory or somewhere else in your `$PATH` with: `sudo mv betty /bin/`

You can now type `betty <filename>` to run the Betty linter.

### Package
Package to install inorder to test `-m32` and `-m64` `gcc` options:

```
vagrant@vagrant-ubuntu-trusty-64:~$ sudo apt-get install libc6-dev-i386
```
