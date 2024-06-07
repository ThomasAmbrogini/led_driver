add_library(led STATIC led_inverted_logic.c)
target_include_directories(led PRIVATE ${CMAKE_SOURCE_DIR}/src/util
                               INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

