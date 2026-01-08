project(library)

add_library(${PROJECT_NAME} 
  src/array.c
  src/tree.c
  src/stack.c
  src/algorithm.c
  src/queue.c
)
add_library(lib::ds ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
