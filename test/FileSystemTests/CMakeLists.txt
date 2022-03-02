file(GLOB SRCS *.h *.cpp)

ADD_EXECUTABLE(FileSystemTests ${SRCS})

target_compile_features(
	FileSystemTests
	PRIVATE
		cxx_std_23
)

target_link_libraries(FileSystemTests MrowrPurr GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

add_test(NAME FileSystemTests COMMAND FileSystemTests)
