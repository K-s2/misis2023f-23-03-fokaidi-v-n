add_library(complex
		complex.hpp
		complex.cpp
)

target_include_directories(complex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
