project(examples)

add_executable(${PROJECT_NAME} example.c)

target_link_libraries(${PROJECT_NAME}
  lib::ds
)
