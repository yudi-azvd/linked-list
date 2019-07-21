cmake_minimum_required(VERSION 3.10.2)

# project(calculator LANGUAGES C CXX)
project(calculator)


include_directories(
	lib/
	lib/list

	core/

	tests/terminal_functions/
	tests/list/
	tests/random_tests/
)

file(GLOB SOURCES
	"core/calculator.c"
	"core/terminal_functions.c"
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

file(GLOB TEST_SOURCES_LIST
	"tests/list/*.cpp"
)

file(GLOB TEST_SOURCES_CALCULATOR
	"tests/calculator/*.cpp"
)

set_source_files_properties(
	TEST_SOURCES_RANDOM_TESTS
	PROPERTIES
		LANGUAGE C
		COMPILE_FLAGS "-Wall -ansi"
)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -ansi")
# é o jeito que deu certo compilar código em C no padrão ANSI.
set(CMAKE_C_FLAGS "-Wall -ansi")

# message(STATUS "random tests: ${TEST_SOURCES_RANDOM_TESTS}")

# add_library(includes ${INC_SOURCES} ${INC_HEADERS})

add_executable(calculator ${SOURCES} main/main.c)
target_link_libraries(calculator ${LIBS})

add_executable(
	test_terminal_functions
	${SOURCES}
 	${TEST_SOURCES_TERMINAL_FUNCTIONS}
)

add_executable(
	test_list
	${SOURCES}
 	${TEST_SOURCES_LIST}
	${LIBS}
)

add_executable(
	test_calculator
	${SOURCES}
 	${TEST_SOURCES_CALCULATOR}
	${LIBS}
)

# Compilar os testes aletórios
# foreach(src_file ${TEST_SOURCES_RANDOM_TESTS})
# 	get_filename_component(executable ${src_file} NAME_WE)
# 	message(STATUS "exec ${executable}")
# 	add_executable(${executable} ${src_file} ${SOURCES})
# 	target_link_libraries(${executable} ${LIBS})
# endforeach(src_file TEST_SOURCES_RANDOM_TESTS)
