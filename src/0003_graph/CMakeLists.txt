# Specify the source files
set(0003GRAPH_SOURCES

    # List down all the source files
    0001_bfs.cc
    0002_dfs.cc

)

# Create a library target
add_library(0003_graph ${0003GRAPH_SOURCES})

target_include_directories(0003_graph PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)