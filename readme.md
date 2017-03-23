[![Build Status](https://travis-ci.org/ifhexa4113/pld-compilo.svg?branch=master)](https://travis-ci.org/ifhexa4113/pld-compilo)

# PLD Compilo
Compiler for a C subset - School project

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
### Windows
```shell
git clone https://github.com/ifhexa4113/pld-compilo.git
cd pld-compilo
make
make run
```

### *nix
```shell
git clone https://github.com/ifhexa4113/pld-compilo.git
cd pld-compilo
make OS=unix
make OS=unix run
```

### Use an input file
Just use flow redirection, like this:
```shell
make run < <path_to_your_file>
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
* **makedir**: create build and bin folders and subfolders.
* **libs**: build the needed libs, and in particular the parser with bison and flex.
* **build**: build the project assuming the parser has already been built.
* **run**: build and run the project.
* **tests**: build and run all the tests, unit and non-regression.
* **nr-tests**: run all non-regression tests.
* **test-%**: run the given non-regression test. Needs the app to be built.
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
under `test/non-regression`.
This folder **must** contain:
* input.cmm: the file that the app will take as input.
* desc: a bit a of text describing your test.

At the moment, non-regression tests will only check if the app
exits with the code `0`, but that's enough for now.

## About IDEs
### CLion
CLion natively uses CMake,
but you can easily tell CMake to make use of your local makefile
[like this](http://stackoverflow.com/questions/26918459/using-local-makefile-for-clion-instead-of-cmake).

### Visual studio
Visual studio doesn't let you use make directly in default projects,
but you can easily set it up to make it work.
[This link](https://msdn.microsoft.com/en-us/library/txcwa2xx.aspx) will surely help.

## About make
No, make **doesn't** only work with Unix bash.
You can perfectly use it in your Windows console, without anything like cygwin.
Take a look at [this link](http://gnuwin32.sourceforge.net/packages/make.htm).

## About compilers for this compiler
Of course, this project will use Regex,
which are a little buggy with some versions of **gcc** and **g++**.

At first sight, **Visual C(++)** and **Clang** look fine.
