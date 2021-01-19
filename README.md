# Test app to generate LLVM IR

This demo C++ uses LLVM Core libs to generate a basic main function.

## Building
* Install LLVM core libs to your system (llvm-dev package in Ubuntu) and update `CMakeLists.txt` file accordingly
* Run the following commands to build
  
        mkdir build
        cd build
        cmake ../
        make
* Generate IR and save
 
        ./codegen > main.ll 
* Compile and run LLVM IR. Then check return code
 
        clang main.ll -o main.out
        ./main.out
        echo $?