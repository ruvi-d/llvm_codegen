cmake_minimum_required(VERSION 3.2)
project(bir_parser VERSION 0.0.1 LANGUAGES CXX)

# App
include_directories(/usr/lib/llvm-11/include)
link_directories(/usr/lib/llvm-11/lib)
file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_subdirectory(runtime)

add_executable(codegen_test ${SOURCES})

add_dependencies(codegen_test rt)

target_link_libraries(codegen_test PRIVATE LLVM-11)
