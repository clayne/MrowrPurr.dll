#include "PapyrusFileSystemTests.h"

class ListingFilesTest : public PapyrusFileSystemTest {};

TEST_F(ListingFilesTest, EmptyFolder) {
    auto dir = CreateTempFolder();
    
    auto results = PapyrusFileSystem::List(nullptr, dir.string());

    EXPECT_EQ(results.size(), 0);
}

TEST_F(ListingFilesTest, OneFile) {
    const auto dir = CreateTempFolder();
    const auto filePath = Path(dir).append("Test.txt");
    
    Touch(filePath);

    auto results = PapyrusFileSystem::List(nullptr, dir.string());

    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0], filePath.string());
}

TEST_F(ListingFilesTest, DoesNotExist) {
    auto results = PapyrusFileSystem::List(nullptr, "C:\\This\\Does\\Not\\Exist");

    EXPECT_EQ(results.size(), 0);
}
