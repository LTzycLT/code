CMake_minimum_required(VERSION 2.8)
project(ML)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_subdirectory(src)
add_subdirectory(test)
