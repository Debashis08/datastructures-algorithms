# Specify the source files
set(0002TREE_SOURCES
    0001_BinarySearchTree.cc
)

# Create a library target
add_library(0002TREE ${0002TREE_SOURCES})

target_include_directories(0002TREE PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)