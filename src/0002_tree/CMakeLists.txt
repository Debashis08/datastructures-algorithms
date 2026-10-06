# Specify the source files
set(0002TREE_SOURCES
    0001_binary_search_tree.cc

)

# Create a library target
add_library(0002_tree ${0002TREE_SOURCES})

target_include_directories(0002_tree PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)