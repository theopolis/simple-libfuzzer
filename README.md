# simple-fuzzer

This is used as a test or example.

## MacOS

You will need to install Homebrew, then install LLVM and cmake

```
brew install llvm cmake
```

Then to build, use the installed LLVM's clang

```
mkdir macos_build; cd macos_build
cmake -DCMAKE_CXX_COMPILER=/usr/local/Cellar/llvm/7.0.0/bin/clang++ ..
make
```

## Ubuntu 18.04

You will need to install clang and cmake

```
sudo apt-get install clang cmake
```

Then to build use

```
mkdir linux_build; cd linux_build
cmake -DCMAKE_CXX_COMPILER=clang++ ..
make
```

If you have `vagrant` installed you can `vagrant up ubuntu18.04`.

## Make sure you're compiling correctly

In the make/compiler output you should see `-fsanitize=fuzzer,address`:

```
[ 25%] Building CXX object CMakeFiles/simple.dir/simple/simple.cpp.o
/usr/local/Cellar/llvm/7.0.0/bin/clang++    -fsanitize-coverage=trace-pc-guard -fsanitize-coverage=trace-cmp -fsanitize=fuzzer,address -std=c++14 -o CMakeFiles/simple.dir/simple/simple.cpp.o -c /Users/reed/git/github/simple-libfuzzer/simple/simple.cpp
```

And it should be linked with the same flag:

```
[100%] Linking CXX executable simple_test
/usr/local/Cellar/cmake/3.11.4/bin/cmake -E cmake_link_script CMakeFiles/simple_test.dir/link.txt --verbose=1
/usr/local/Cellar/llvm/7.0.0/bin/clang++   -Wl,-search_paths_first -Wl,-headerpad_max_install_names  CMakeFiles/simple_test.dir/main.cpp.o  -o simple_test -fsanitize=address libsimple.a -fsanitize=fuzzer -fsanitize=address
```

## Run the harness

```
./simple_harness
```

Steps to demonstrate fuzzing
- Look at `simple/simple.cpp` for `TODO[1]` and comment out the location where the exception does not pass through. Uncomment the section that drops the exception. The same applies to `TODO[2]`/
- The `TODO[3]` will prevent the harness from hitting default RSS limits. This is a common problem with basic harnesses but the example here is contrived.
- Look at `CMakeList.txt` and comment out the coverage lines. Do the same in `simple/simple.cpp` to challenge the harness to work harder to find a crash. Rebuild with `cmake` and `make` then `time ./simple_harness` and see the difference.
