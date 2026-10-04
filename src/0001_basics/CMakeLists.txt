# Define the source files for the library
set(0001BASICS_SOURCES
    0001_node.cc
)

# Create the library target
add_library(0001_basics ${0001BASICS_SOURCES})

# Add the header directory to the target's include paths
target_include_directories(0001_basics PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)