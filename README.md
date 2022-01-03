# blockhead
Blocks, and lambdas, and clang... oh my.

The Block type extention introduced by Apple seems to be broken, buggy, and all around horrible.  Can we exploit it?

You need CMake >= 3.15

## Linux
sudo apt-get install llvm
sudo apt-get install clang
sudo apt-get install libblocksruntime-dev

cmake -D CMAKE_CXX_COMPILER=clang++ ..
cmake --build .

## MacOS
cmake ..
cmake --build .

## Windows:
Build the llvm-project (and clang along with it):

https://clang.llvm.org/get_started.html

cd blockhead/cpp

Run...
> clang++ -fblocks main.cpp -o blockhead_cpp.exe

Puzzle over why it will not link.

## Links

https://en.wikipedia.org/wiki/Blocks_(C_language_extension)
