cmake_minimum_required(VERSION 3.7)

if(NOT DEFINED ${BUILD_NUMBER})
  message("NOT DEFINED BUILD_NUMBER")
  message("Try to define")
  set(BUILD_NUMBER "0")
else("${BUILD_NUMBER}" == "*")
  set(BUILD_NUMBER "0")
endif()

### MATH(EXPR ENV{TRAVIS_BUILD_NUMBER} "$ENV{BUILD_NUMBER} + 1")

project(helloworld VERSION 1.0.${BUILD_NUMBER} )

set(PROJECT_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${PROJECT_VERSION_PATCH})

configure_file(lib/version.h.in lib/version.h)

add_executable(helloworld src/program.cpp)

set_target_properties(helloworld PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
  COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set_target_properties( helloworld
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )

add_library(LibVersion lib/hello_func.cpp)

### Добавляем тесты

include(cmake/gtest.cmake)
fetch_googletest(
	${PROJECT_SOURCE_DIR}/cmake
	${PROJECT_BINARY_DIR}/gtest
)
enable_testing()
add_subdirectory(test)

target_link_libraries(helloworld LibVersion)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_OUTPUT_FILE_PREFIX packages)

set(CPACK_PACKAGE_CONTACT kovalski2006@yandex.ru)

include(CPack)
