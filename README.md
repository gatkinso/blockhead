# blockhead
Blocks, and lambdas, and clang... oh my.

You need CMake >3.19

Linux:
sudo apt-get install llvm
sudo apt-get install clang
sudo apt-get install libblocksruntime-dev

cmake -D CMAKE_CXX_COMPILER=clang++ ..
cmake --build .

Mac:
cmake ..
cmake --build .

Windows:
Oy.
