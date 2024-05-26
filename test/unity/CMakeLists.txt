include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(led_driver_test led_driver_test.c)
target_link_libraries(led_driver_test led unity)
add_test(led_driver_test led_driver_test)

