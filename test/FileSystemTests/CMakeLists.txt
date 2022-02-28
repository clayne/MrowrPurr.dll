file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(FileSystemTests ${SRCS})

target_compile_features(
	FileSystemTests
	PRIVATE
		cxx_std_23
)

target_link_libraries(FileSystemTests FileSystem GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_test(NAME FileSystemTests COMMAND FileSystemTests)
