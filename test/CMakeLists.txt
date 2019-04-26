add_executable(
	unit_tests
	src/Main_TestAll.cpp
	src/LibVersion_Test.cpp
)

target_link_libraries(
	unit_tests
	gtest_main
	LibVersion
)

add_test(
	NAME
	  unit
	COMMAND
	  ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_DIR}/unit_tests
)