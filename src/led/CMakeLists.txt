include_directories(${CMAKE_SOURCE_DIR}/src/util)
file(GLOB SOURCES ./*.c)
add_library(led STATIC led_inverted_logic.c)

