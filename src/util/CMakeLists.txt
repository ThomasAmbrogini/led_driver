add_library(util_mock STATIC runtime_error_mock.c)
target_include_directories(util_mock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

