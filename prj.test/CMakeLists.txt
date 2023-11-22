add_executable(test_complex test_complex.cpp)

target_include_directories(test_complex PUBLIC prj.lab)

target_link_libraries(test_complex complex)
