#include "TestHelper.h"

class PredicatesTest : public PapyrusFileSystemTest {};

TEST_F(PredicatesTest, Exists) {
    auto dir = CreateTempFolder();
    const auto filePath = fs::path(dir).append("Test.txt");
    Touch(filePath);
    
    EXPECT_TRUE(PapyrusFileSystem::Exists(nullptr, dir.string()));
    EXPECT_TRUE(PapyrusFileSystem::Exists(nullptr, filePath.string()));
    EXPECT_FALSE(PapyrusFileSystem::Exists(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}

TEST_F(PredicatesTest, IsFile) {
    auto dir = CreateTempFolder();
    const auto filePath = fs::path(dir).append("Test.txt");
    Touch(filePath);
    
    EXPECT_FALSE(PapyrusFileSystem::IsFile(nullptr, dir.string()));
    EXPECT_TRUE(PapyrusFileSystem::IsFile(nullptr, filePath.string()));
    EXPECT_FALSE(PapyrusFileSystem::IsFile(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}

TEST_F(PredicatesTest, IsDirectory) {
    auto dir = CreateTempFolder();
    const auto filePath = fs::path(dir).append("Test.txt");
    Touch(filePath);
    
    EXPECT_TRUE(PapyrusFileSystem::IsDirectory(nullptr, dir.string()));
    EXPECT_FALSE(PapyrusFileSystem::IsDirectory(nullptr, filePath.string()));
    EXPECT_FALSE(PapyrusFileSystem::IsDirectory(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}