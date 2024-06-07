add_executable(led_driver_test led_driver_test.c)
target_link_libraries(led_driver_test led unity util_mock)

add_test(led_driver_ctest ../../bin/led_driver_test)

