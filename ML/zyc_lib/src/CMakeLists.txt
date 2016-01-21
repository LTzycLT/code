add_subdirectory(generator)
add_subdirectory(random)

add_library(libml classification.cpp)
set_target_properties(libml PROPERTIES OUTPUT_NAME "ml")

target_link_libraries(libml)
