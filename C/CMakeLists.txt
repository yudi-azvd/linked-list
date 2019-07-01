cmake_minimum_required(VERSION 3.10.2)

project(calculator)

# Bring the headers, such as Student.h into the project
include_directories(
	lib/

	tests/
)

# -lsqlite3

# SET(GCC_COVERAGE_COMPILE_FLAGS "-lsqlite3")
# SET(GCC_COVERAGE_LINK_FLAGS    "-lsqlite3")
# set (CMAKE_CXX_FLAGS "-lsqlite3")

# Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES
	
)

file(GLOB TEST_SOURCES_DOMAINS
	"test/tests_domains/*.cpp"
)

file(GLOB TEST_SOURCES_DATABASE
	"test/tests_database/*.cpp"
)

file(GLOB TEST_SOURCES_INTERFACES
	"test/tests_interfaces/*.cpp"
)

####
file(
	GLOB INC_SOURCES
	"src/domains/*.cpp"
)

file(
	GLOB INC_HEADERS
	"include/domains/*.h"
	"include/entities/*.h"
	"include/database/*.h"

	"include/backend/*.h"
	"include/interfaces/*.h"
)

set(LIBS sqlite3)

add_compile_options(-l sqlite3)

list(REMOVE_ITEM INC_HEADERS "database_sketch.h")
# add_library(includes ${INC_SOURCES} ${INC_HEADERS})

add_executable(the-ticket-booth-cmake ${SOURCES} src/main.cpp)
target_link_libraries(the-ticket-booth-cmake ${LIBS})


# eu não devia precisar linkar a biblioteca do database
# a nível de domínios...
add_executable(test_domains ${SOURCES} ${TEST_SOURCES_DOMAINS})
target_link_libraries(test_domains ${LIBS})

add_executable(test_database ${SOURCES} ${TEST_SOURCES_DATABASE})
target_link_libraries(test_database ${LIBS})

add_executable(test_interfaces ${SOURCES} ${TEST_SOURCES_INTERFACES})
target_link_libraries(test_interfaces ${LIBS})
