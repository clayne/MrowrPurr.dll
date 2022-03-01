#include "TestHelper.h"

class PredicatesTest : public PapyrusFileSystemTest {};

TEST_F(PredicatesTest, Exists) {
    const auto folder = MkDir("Hello");
    const auto file = Touch("Hello\\Test.txt");

    EXPECT_TRUE(PapyrusFileSystem::Exists(nullptr, folder));
    EXPECT_TRUE(PapyrusFileSystem::Exists(nullptr, file));
    EXPECT_FALSE(PapyrusFileSystem::Exists(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}

TEST_F(PredicatesTest, IsFile) {
    const auto folder = MkDir("Hello");
    const auto file = Touch("Hello\\Test.txt");
    
    EXPECT_FALSE(PapyrusFileSystem::IsFile(nullptr, folder));
    EXPECT_TRUE(PapyrusFileSystem::IsFile(nullptr, file));
    EXPECT_FALSE(PapyrusFileSystem::IsFile(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}

TEST_F(PredicatesTest, IsDirectory) {
    const auto folder = MkDir("Hello");
    const auto file = Touch("Hello\\Test.txt");
    
    EXPECT_TRUE(PapyrusFileSystem::IsDirectory(nullptr, folder));
    EXPECT_FALSE(PapyrusFileSystem::IsDirectory(nullptr, file));
    EXPECT_FALSE(PapyrusFileSystem::IsDirectory(nullptr, "C:\\This\\Totally\\Does\\Not\\Exist"));
}