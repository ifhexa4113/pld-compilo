[![Build Status](https://travis-ci.org/ifhexa4113/pld-compilo.svg?branch=master)](https://travis-ci.org/ifhexa4113/pld-compilo)

# PLD Compilo
Compiler for a C subset - School project.

_For those who are not reading this from Github or anything able to parse Markdown syntax,
please read it here for a better experience: https://github.com/ifhexa4113/pld-compilo#readme ._

Here are the following sections:
* [Important notes](https://github.com/ifhexa4113/pld-compilo#important-notes)
* [What it can do](https://github.com/ifhexa4113/pld-compilo#what-it-can-do)
* [What it can't do](https://github.com/ifhexa4113/pld-compilo#what-it-cant-do)
* [Prerequisites](https://github.com/ifhexa4113/pld-compilo#prerequisites)
* [Build and run](https://github.com/ifhexa4113/pld-compilo#build-and-run)
* [How to](https://github.com/ifhexa4113/pld-compilo#how-to)
* [About](https://github.com/ifhexa4113/pld-compilo#about)

## Important notes
* The final binary will be located under `bin/gmm.exe`.
* By default, the compiler will take the standard input as input.
Use flow redirect to read from a file.
* By default, the generated assembly code will be generated where you run the compiler,
and be named `out.s`.
* By default, the generated IR code will be generated where you run the compiler,
and named `ir.out`.
* By default, the behavior of the compiler is just analyze the program and check for
lexical, syntaxical and semantical errors,and prints them in the standard error output.
See [Build and run](https://github.com/ifhexa4113/pld-compilo#build-and-run) for other options.
* The default targeted architecture is Windows 64 bits (so it runs on 32 bits),
but it should work on linux 64 bits too (it may fail, so please contact us if it happens).

## What it can do
### Front
The _front end_ supports all grammar elements in [this document](https://docs.google.com/document/d/10C3HYx7YhTvENkOxZ0VfLxvc-e988D4XSYGAnqD4OSI/edit?usp=sharing).
Please note that this is a bit different from the original grammar.
In other words, here's a list of what our _front-end_ handles:
* All C operators, as described [here](https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B) except unary `-` due to initial subject handling only unsigned types
* Variables and functions types `uint32_t`, `uint64_t`, `int32_t`, `int64_t`, `char`
* Variable declaration of the previous types, **in any context** except global (i.e. anywhere in the code but globally)
* Array (one dimension) declarations and definitions of the previous types, **in any context** except global (i.e. anywhere in the code but globally)
* Function declaration, `void` or of the previous types, in a global context only
* Variable definition, **in any context** except global (i.e. anywhere in the code but globally)
* Function definition, in a global context only
* One-lined variables and arrays definitions and declarations, **in any context** except global. Example: `char c = ‘a’, d[4], e[] = {1, 2, 3}, f;`
* Literal constants, such as `'a'`, `3`, `'\033'`
* Array size inference. Example: `char a[] = {1, 2, '\n'};` is recognized as an array of size 3
* Blocks and recursive blocks. Example: `void main() {{{char a = 0;}}}` is valid, but `void main() {{{char a = 0;} a++;}}` is not
* **Variables scopes**
* Conditional structures: `if`, `if/else`, `for`, `while`. **All of them may have an empty condition**
* One-lined conditional structures, such as `if(0) i++;`
* Empty increment and/or init `for`. Example: `for(;;)`
* Jump keywords: `break`, `continue`, `return` (`break`, `continue` are only accepted in a loop context)
* Function call, with the right number of parameters
* Expression anywhere in the code, except for array size (it must be a constant literal number, as in `char a[3];`)
* `putchar` and `getchar` system functions
* Parenthesised expressions and operators priority
* Evaluate boolean expressions. Example: `char a = 'a' > 'b';` ; here `a` is `0`;

It will throw an error in the following cases (stopping the compilation before the back-end,
but at the end of the front-end):
* Using a variable before / without declaring it
* Using a function before / without declaring it
* Declaring the same variable / function several times
* Using a function without the right number of arguments
* Using a void-like variable / function in an expression
* Returning an inappropriate type in a function
* Missing _return_ statement in a non-void function

### Back
The _back_end_ uses an **intermediate representation** that you can find [here](https://docs.google.com/document/d/1i9oeq-KPHWqFv4FRP_JWdbpCB8o-nnOXmOeIyHCe9-k/edit?usp=sharing).
It uses an infinite numbers of registers and some basic operations.
It then translates it into the targeted language.
Here's what it can do:
* Conditional jump (`if`), with or without `else` clause
* `+ ++` operators
* Parenthesised operations, infinitely
* Variables scopes
* Binary operators `> >= < <= && !=`
* `while` loops, with or without block nor condition
* Variables definitions and declarations
* Functions definitions and declarations
* Boolean expressions evaluation
* `putchar` call
* Variable assignation (`=`, `+=`)
* **One lined multiple variables assignation**

Here's an example of a program we can compile and run:
```c
void main()
{
    char a = 'a';
    while(a <= 'z') {
        if(a == 'q') {
            putchar('!');
        } else {
            putchar(a);
        }
        a++;
    }
}
```
With the following command:
```shell
bin\gmm.exe test.c -c
gcc out.s
a.exe
```

The output is:
```shell
abcdefghijklmnop!rstuvwxy
```

## What it can't do
### Front
Basically, here are some functionalities that our compiler doesn't support compared to C:
* Preprocessing (`#include<something>` are ignored, other directives are unsupported)
* Variables/arrays definitions/declarations in a global context
* Functions declarations/definitions in a non-global context
* Array sizes as non-literal numbers. Example: `char a[1 + 2];`

### Back
What our compiler can't do is mostly due to the backend, and a lack of time.
**Most of the front is supported by the IR, but not by the generated assembly code after it.**
Here's some features that the front supports, but not the back:
* Array definitions
* Non-void function calls and with arguments (other than `putchar`), sadly
* `break` and `continue` keywords, anywhere
* `for` loop, but that's pretty similar to `while` and easy to do
* `-`, `*`, `%` and `/` operations, but that's pretty easy too
* Shift operations
* `||` operator, but that's pretty similar to `&&` and easy to do
* ... And everything else listed in the front but not in the back

## Prerequisites
### About Windows
Flex and Bison are not really easy to build with windows.
Fortunately, there is a great package called
[Win flex-bison](https://github.com/lexxmark/winflexbison)
that will let you install both directly,
or build it through Visual Studio 2010 and higher.

Take a look at [this documentation](https://sourceforge.net/p/winflexbison/wiki/Visual%20Studio%20custom%20build%20rules/)
for more information.

### Flex
Flex is a fast lexical analyzer generator.

You'll need the [Flex utility tool](https://github.com/westes/flex/releases).
2.6.3 is the current version at the time of this project.
Also, be sure to add it to your path!

_For windows, this may be complicated. See the previous section_.

### Bison
> Bison is a general-purpose parser generator that converts
a grammar description for an LALR(1) context-free grammar
into a C program to parse that grammar.

You'll find it [here](https://www.gnu.org/software/bison/).
To install it, [this documentation](https://geeksww.com/tutorials/miscellaneous/bison_gnu_parser_generator/installation/installing_bison_gnu_parser_generator_ubuntu_linux.php)
may help.
Also, be sure to add it to your path!

_For windows, this may be complicated.
See the previous section called **About Windows**_.

### Make
Be sure to have a GNU make installed (whether on *nix or a *nix-like environment
like cygwin or even directly on your windows)
and that the path to the executable is in your PATH variable.

### g++
By default, the project uses g++ as compiler with the flag `-std=gnu++11`.
Be sure that everything will work with it.

## Build and run
Once built, the compiler is located under `bin/gmm.exe`.
You can run it with `make run` but it won't take any options.
`bin/gmm.exe --help` will show you how to use it.

### Parameters
You can pass 0 to 2 parameters:
* No parameters: default input is stdout.
* One parameter: the path to the file to read, or an option.
* Two parameters: the path to the file to read and an option.
* More parameters: error. You can't do that.

The options are:
* `-h` : (or --help) prints the help.
* `-i` : generates IR code into ir.out
* `-c` : generates assembly code into out.s

Please note that these options are exclusive.

To use an input file, just pass its path as a parameter:
```shell
./bin/gmm.exe path_to_your_file
```

Note that you can use the previous options and provide a path.

### Windows
```shell
git clone https://github.com/ifhexa4113/pld-compilo.git
cd pld-compilo
make
bin\gmm.exe
```

### *nix
```shell
git clone https://github.com/ifhexa4113/pld-compilo.git
cd pld-compilo
make OS=unix
./bin/gmm.exe
```

### Run all the tests
To build and run the tests (unit and non-regression),
you just have to run the following command:
```shell
make tests
```

Note that this will build the app **and** the unit-test app.
The unit-test app will be run first, then each non-regression test
will be run if the others succeeded.

### Make rules
* **all** (default): build the whole project, but not the tests.
* **u-tests**: build the unit tests and everything it needs.
* **nr-tests**: build the non-regression tests and everything it needs.
* **makedir**: create build and bin folders and subfolders.
* **libs**: build the needed libs, and in particular the parser with bison and flex.
* **build**: build the project assuming the parser has already been built.
* **run**: run the project.
* **run-utests**: run the unit tests.
* **run-nrtests**: run the non-regression tests.
* **tests**: build and run all the tests, unit and non-regression.
* **test-tree**: copy the folders' tree in `src` under `test`. Same for libs.
* **clean**: remove all .o files.
* **mrproper**: remove whole build and bin folders.
* **print-%**: show a makefile variable. Example: `make print-DEBUG` -> `yes`

Notes:
* Any rule on *nix: `make <rule> OS=unix`
* Debug mode (default: yes): `make DEBUG=no`
* Change compiler (default: g++): `make CC=<your compiler>`

## HOW TO
### How to write unit test
All unit tests are located in a folder `test` next to `src`.
This is true even for libs in `lib`.
`src` and `test` **must** have the same folders' tree,
but `test` can have more folders if needed.

To avoid copying the folders' tree of `src` into `test` by hand,
just run the following command:
```shell
make test-tree
```

Note that this will not erase any folders nor files, won't fail if
the folders already exist, and works for libs under `lib` too.

Then, just write a `.spec.cpp` file at the location of the class you want
to test. For example, if you want to test `src/module1/module.cpp`,
you need to create a file `test/module1/module.spec.cpp`.
This file must have the following shape:
```c++
#include "module1/module.h"
#include "catch.h"

TEST_CASE("Simple module1 test", "")
{
    REQUIRE([...]);
}
```

take a look at the [catch doc](https://github.com/philsquared/Catch)
for more information about how to write unit tests with catch.

### How to write non-regression tests
Non-regression tests are here to test if the app works _globally_.
To write one, you need to create a folder named after your test
under `test/set`.
This folder **must** contain:
* input.cmm: the file that the app will take as input.
* desc: a bit a of text describing your test.

At the moment, non-regression tests will only check if the app
exits with the code `0`, but that's enough for now.

## About

### About IDEs
#### CLion
CLion natively uses CMake,
but you can easily tell CMake to make use of your local makefile
[like this](http://stackoverflow.com/questions/26918459/using-local-makefile-for-clion-instead-of-cmake).

#### Visual studio
Visual studio doesn't let you use make directly in default projects,
but you can easily set it up to make it work.
[This link](https://msdn.microsoft.com/en-us/library/txcwa2xx.aspx) will surely help.

### About make
No, make **doesn't** only work with Unix bash.
You can perfectly use it in your Windows console, without anything like cygwin.
Take a look at [this link](http://gnuwin32.sourceforge.net/packages/make.htm).