add_library(complex
		complex.hpp
		complex.cpp
)
add_executable(rational rational.cpp)

target_include_directories(complex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
