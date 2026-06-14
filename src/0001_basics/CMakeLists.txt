# Specify the source files
set(0001BASICS_SOURCES
    Node.cc
)

# Create a library target
add_library(0001_Basics ${0001BASICS_SOURCES})

target_include_directories(0001_Basics PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)