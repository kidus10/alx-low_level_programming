# Low Level Programming

*Description of all the directories in here are listed below.*

* 0x00-hello_world :- Contains programs that mostly deal with **C compiler** in Linux or `gcc`.

* 0x01-variables_if_else_while :- Contains C programs that deals with **conditional statement** `if else` and the `while`**loop**.

* 0x02-functions_nested_loops :- Contains **C programs** that deals with `functions` and **nested** `loops`.

* 0x03-debugging :- Contains **C programs** that are `debugged` and **fixed**.

* 0x04-more_functions_nested_loops :- Contains **C programs** that deals more about **functions** and **nested** `loops`.

* 0x05-pointers_arrays_strings :- Contains **programs** and **functions** that deal with `pointers`, `arrays` and `strings`.

* 0x06-pointers_arrays_strings :- Contains **programs** and **functions** that deals more about `pointers`, `arrays` and `strings`.

* 0x07-pointers_arrays_strings :- Contains **programs** and **functions** that deals even more about `pointers`, `arrays`     and `strings`.

* 0x08-recursion :- Contains **programs** and **functions** that deal with `recursions`.

* 0x09-static_libraries :- Contains `files` and `script` that deal with `static libraries` in `C`.

* 0x0A-argc_argv :- Contains **programs** and **functions** that deal with **implementation** of `argc` and `argv` parameters  of the `main` function.

* 0x0B-malloc_free :- Contains **programs** and **functions** that deal with `malloc`.

* 0x0C-more_malloc_free :- Contains **programs** and **functions** that deal more about `malloc`.

* 0x0D-preprocessor :- Contains **programs** and **functions** that deal with `preprocessor`.

* 0x0E-structures_typedef :- Contains **programs** and **functions** that deal with `structures` and `typedef`.

* 0x0F-function_pointers :- Contains **programs** and **functions** that deal with `function pointers`.

* 0x10-variadic_functions :- Contains **programs** and **functions** that deal with `variadic functions`.

* 0x12-singly_linked_lists :- Contains **programs** and **functions** that deal with `singly linked lists`.

## Useful Tools

***Some important Tools and Resources***

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
* Once saved, exit file and `change permissions` to apply to all users with:
```
chmod a+x betty
```
* `Move` the `betty` file into `/bin/` directory or somewhere else in your `$PATH` with:
```
sudo mv betty /bin/
```
You can now type `betty <filename>` to run the Betty linter.

### Vagrant

#### How to install Vagrant on your personal computer

##### Windows

* Download [VirtualBox](https://www.virtualbox.org/wiki/Downloads)
* Install VirtualBox
* Download [Vagrant](https://www.vagrantup.com/downloads)
* Install Vagrant
* Open the command prompt
* Add the **Ubuntu 20.04** (`trusty64`) image to your box list:

```
vagrant box add ubuntu/trusty64
```

* Create your first virtual machine:

```
vagrant init ubuntu/trusty64
```

This will generate a `Vagrantfile` with `base = "ubuntu/trusty64"` - *you don’t have to execute this command line everyday, only once, to create a new virtual machine*

```
vagrant plugin install vagrant-vbguest
```

This is to avoid issue with the lastest version of `Vagrant`.

```
vagrant up
```

This will start your virtual machine

```
vagrant ssh
```

Now you are inside your `virtual machine`.

```
vagrant@vagrant-ubuntu-trusty-64:~$
```

### Package
Package to install inorder to test `-m32` and `-m64` `gcc` options:

```
sudo apt-get install libc6-dev-i386
```
