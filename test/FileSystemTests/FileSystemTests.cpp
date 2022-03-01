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

///////////////////////////////////////////////////////

class PredicatesTest : public PapyrusFileSystemTest {};

TEST_F(PredicatesTest, Exists) {
    auto dir = CreateTempFolder();
    const auto filePath = Path(dir).append("Test.txt");
    Touch(filePath);
    
    EXPECT_TRUE(PapyrusFileSystem::Exists(nullptr, dir.string()));
    EXPECT_TRUE(PapyrusFileSystem::Exists(nullptr, filePath.string()));
    EXPECT_FALSE(PapyrusFileSystem::Exists(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}

TEST_F(PredicatesTest, IsFile) {
    auto dir = CreateTempFolder();
    const auto filePath = Path(dir).append("Test.txt");
    Touch(filePath);
    
    EXPECT_FALSE(PapyrusFileSystem::IsFile(nullptr, dir.string()));
    EXPECT_TRUE(PapyrusFileSystem::IsFile(nullptr, filePath.string()));
    EXPECT_FALSE(PapyrusFileSystem::IsFile(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}

TEST_F(PredicatesTest, IsDirectory) {
    auto dir = CreateTempFolder();
    const auto filePath = Path(dir).append("Test.txt");
    Touch(filePath);
    
    EXPECT_TRUE(PapyrusFileSystem::IsDirectory(nullptr, dir.string()));
    EXPECT_FALSE(PapyrusFileSystem::IsDirectory(nullptr, filePath.string()));
    EXPECT_FALSE(PapyrusFileSystem::IsDirectory(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}
