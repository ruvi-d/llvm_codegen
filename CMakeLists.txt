cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0091 NEW)
project(bir_parser VERSION 0.0.1 LANGUAGES CXX)

# Find and loacd LLVM components
find_package(LLVM 11 REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
llvm_map_components_to_libnames(llvm_libs codegen)

file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
add_executable(codegen_test ${SOURCES})
set_property(TARGET codegen_test PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
target_link_libraries(codegen_test PRIVATE ${llvm_libs})
