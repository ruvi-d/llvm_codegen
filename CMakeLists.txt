cmake_minimum_required(VERSION 3.2)
project(bir_parser VERSION 0.0.1 LANGUAGES CXX)

# App
include_directories("C:\\Users\\ruvi\\projects\\llvm-11.0.1.src\\install\\include")
link_directories("C:\\Users\\ruvi\\projects\\llvm-11.0.1.src\\install\\lib")
file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
add_executable(codegen_test ${SOURCES})
target_link_libraries(codegen_test PRIVATE LLVM-C
LLVMBinaryFormat
LLVMBitReader
LLVMBitstreamReader
LLVMCodeGen
LLVMCore
LLVMRemarks
LLVMSupport
)
