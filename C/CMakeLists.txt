cmake_minimum_required(VERSION 3.10.2)

# project(calculator LANGUAGES C CXX)
project(calculator)
# set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -ansi")

# Bring the headers, such as Student.h into the project
include_directories(
	lib/
	lib/list

	include/

	src/

	tests/terminal_functions/
	tests/random_tests/
)

# Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.c src/Student.c)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES
	"src/terminal_functions.c"
)

file(GLOB LIBS
	"lib/list/*.c"
	"lib/list/*.h"
)
add_library(libs ${LIBS})

file(GLOB TEST_SOURCES_TERMINAL_FUNCTIONS
	"tests/terminal_functions/*.cpp"
)

file(GLOB TEST_SOURCES_RANDOM_TESTS
	"tests/random_tests/*.c"
)

# message(STATUS "random tests: ${TEST_SOURCES_RANDOM_TESTS}")


# add_library(includes ${INC_SOURCES} ${INC_HEADERS})

add_executable(calculator ${SOURCES} src/calculator.c)
target_link_libraries(calculator ${LIBS})

add_executable(
	test_terminal_functions
	${SOURCES}
 	${TEST_SOURCES_TERMINAL_FUNCTIONS}
)

# compilar os testes aletórios
foreach(src_file ${TEST_SOURCES_RANDOM_TESTS})
	get_filename_component(executable ${src_file} NAME_WE)
	message(STATUS "exec ${executable}")
	add_executable(${executable} ${src_file} ${SOURCES})
	target_link_libraries(${executable} ${LIBS})
endforeach(src_file TEST_SOURCES_RANDOM_TESTS)
