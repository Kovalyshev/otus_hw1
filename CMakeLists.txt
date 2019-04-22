cmake_minimum_required(VERSION 3.7)

set(BUILD_VERSION, $ENV{TRAVIS_BUILD_NUMBER})

if($BUILD_VERSION)
  set(BUILD_VERSION}, 0)
endif()

project(helloworld VERSION 1.0.${TRAVIS_BUILD_NUMBER} )

configure_file(lib/version.h.in lib/version.h @ONLY)

add_executable(helloworld src/program.cpp)

add_library(helloworld_lib lib/hello_func.cpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set_target_properties( helloworld
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )

target_link_libraries(helloworld helloworld_lib)