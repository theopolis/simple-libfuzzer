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
cmake -DCMAKE_CXX_COMPILER=/usr/local/Cellar/llvm/7.0.0/bin/clang++
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
cmake -DCMAKE_CXX_COMPILER=clang++
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

