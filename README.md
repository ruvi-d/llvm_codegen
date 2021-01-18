# Test app using [Kaitai](http://kaitai.io/)

This demo app will uses Kaitai lib to parse a binary file. The schema is defined in a Kairai specific format and is saved to as a text file with the *.ksy extension.

## Setting up Kaitai
* Install `kaitai-struct-compiler` package to generate binary reader source code.
  * Instructions to add deb repo: http://kaitai.io/
* Clone C++ runtime: https://github.com/kaitai-io/kaitai_struct_cpp_stl_runtime
  * Build and Install using
 
        cd build
        cmake ../
        make
        sudo make install

## Generate a Ballerina IR (BIR) sample file
* Create a simple Ballerina (*.bal) file and compile it with the `--dump-bir-file=fine_name` flag
 
        ballerina build --dump-bir-file=dump_file_name source.bal 
* Obtain the bir.ksy file corresponding to the Ballerina compiler version that was used: https://github.com/ballerina-platform/ballerina-lang/blob/master/docs/bir-spec/src/main/resources/kaitai/bir.ksy
* Validate that the dump_file and ksy are compatible using https://ide.kaitai.io

## Building
* Generate the binary file parser source code
  
        kaitai-struct-compiler --target cpp_stl --cpp-namespace ballerina bir.ksy
* Build test app
 
        clang++ -g -lkaitai_struct_cpp_stl_runtime main.cpp bir.cpp 
* Run app
 
        export LD_LIBRARY_PATH=/usr/local/lib/
        ./a.out