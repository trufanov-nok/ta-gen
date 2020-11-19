cmake_minimum_required (VERSION 2.8.11)

PROJECT(ta-gen)

FIND_PACKAGE(Boost COMPONENTS program_options)
IF(NOT Boost_FOUND)
        MESSAGE(
                FATAL_ERROR
                "Could not find boost headers or libraries. "
                "You may need to install a package named libboost1.35-dev or similarly. "
                "Hint: create a Boost_DEBUG variable in cmake and set it to YES."
        )
ENDIF(NOT Boost_FOUND)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

set(ta-gen_SRC 
	${ta-gen_SOURCE_DIR}/main.cpp
	${ta-gen_SOURCE_DIR}/prints.cpp
	${ta-gen_SOURCE_DIR}/utils.cpp
	)

add_executable (ta-gen ${ta-gen_SRC})

target_link_libraries(ta-gen LINK_PUBLIC ta-lib-rt boost_program_options)
