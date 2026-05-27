project(library)

add_library(${PROJECT_NAME} 
  src/array.c
  src/list.c
  src/stack.c
)
add_library(lib::ds ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)
