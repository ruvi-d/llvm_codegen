# Test app to generate LLVM IR

This demo C++ uses LLVM Core libs to generate a basic main function.

## Building
* Download and build LLVM-src to your system update `CMakeLists.txt`'s header include and lib path accordingly.
* Run the following commands to build
  
        mkdir build
        cd build
        cmake ../
        msbuild ALL_BUILD.vcxproj /p:configuration=Debug
* Generate IR and save
 
        ./Debug/codegen.exe > main.ll
* Open main.ll from notepad.exe and save as utf-8 encoding 
* Compile and run LLVM IR. Then check return code
 
        clang main.ll -o main.exe
        ./main.exe
        echo $LASTEXITCODE 