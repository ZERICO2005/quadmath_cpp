cmake_minimum_required(VERSION 3.12)

set(SRC_DIR "./src")

set(PROJECT_NAME "quadmath-cpp-test")
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin")

# Compiling
	set(CMAKE_C_COMPILER "gcc")
	set(CMAKE_CXX_COMPILER "g++")

# Set C and C++ standards
	set(CMAKE_C_STANDARD 99)
	set(CMAKE_CXX_STANDARD 11)

# Compiler Flags
	set(OPT_FLAG -O2 -g)

# Source Files
	file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.c" "${SRC_DIR}/*.cpp")

	add_executable(${PROJECT_NAME} ${SRC_FILES})

# Compile Options

	target_compile_options(${PROJECT_NAME} PRIVATE
		${OPT_FLAG}
		-Wall -Wextra -Wpedantic -Wshadow -Wfloat-conversion -Wconversion -Wformat=2
	)

	target_link_libraries(${PROJECT_NAME} PRIVATE "quadmath")
