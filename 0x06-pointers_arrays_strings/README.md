# C - More pointers, arrays and strings

*Description or function of all the programs in this directory are listed below.*

* 0-strcat.c :- a function that `concatenates` two `strings`.
  * This function `appends` the `src string` to the `dest string`, overwriting the terminating `null byte` (`\0`) at the end of `dest`, and then `adds` a terminating `null byte`
  * Returns a `pointer` to the resulting string `dest`

* 1-strncat.c :- a function that concatenates two strings.
  * This `_strncat` function is similar to the `_strcat` function, except that:
    * It will use at most `n` bytes from `src`
    * `src` does not need to be `null-terminated` if it contains `n` or more bytes
  * Return a pointer to the resulting string dest

* 2-strncpy.c :- a function that `copies` a `string`.

* 3-strcmp.c :- a function that `compares` two `strings`.

* 4-rev_array.c :- a function that `reverses` the content of an `array` of `integers` where `n` is the number of `elements` of the `array`.

* 5-string_toupper.c :- a function that **changes** all `lowercase` letters of a `string` to `uppercase`.

* 6-cap_string.c :- a function that `capitalizes` all `words` of a `string`.
  * Separators of words can be:
    * `space`, `tabulation`, `new line`, `,`, `;`, `.`, `!`, `?`, `"`, `(`, `)`, `{`, and `}`

* 7-leet.c :- a function that `encodes` a `string` into `1337`.
  * Letters `a` and `A` should be replaced by `4`
  * Letters `e` and `E` should be replaced by `3`
  * Letters `o` and `O` should be replaced by `0`
  * Letters `t` and `T` should be replaced by `7`
  * Letters `l` and `L` should be replaced by `1`

* 100-rot13.c :- a function that `encodes` a string using `rot13`.

* 101-print_number.c :- a function that `prints` an `integer`.

* 102-magic.c :- Add `one line` to [this code](https://github.com/holbertonschool/make_magic_happen/blob/master/magic.c), so that the program prints `a[2] = 98`, followed by a new line.
  * It's not allowed to `use` the variable `a` in your new line of code
  * It's not allowed to `modify` the variable `p`
  * It's not allowed to use `,`
  * The code should be written at line `19`, before the `;`
  * Do not `remove` anything from the initial code, not even the `comments`
  * Do not `change` anything but the line of code you are adding (don’t change the `spaces` to `tabs`!)
  * Allowed only to write `one` statement

* 103-infinite_add.c :- a function that adds two numbers.
  * Assuming that you will always get `positive numbers` or `0`
  * Assuming that there will be only `digits` in the strings `n1` and `n2`
  * `n1` and `n2` will never be `empty`
  * If the result can not be `stored` in `r` the function must return `0`
