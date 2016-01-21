include_directories(${PROJECT_SOURCE_DIR}/generator})
add_executable(test test.cpp)
target_link_libraries(test libgenerator librandom libml)
