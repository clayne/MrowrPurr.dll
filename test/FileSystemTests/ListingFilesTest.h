#include "TestHelper.h"

class ListingFilesTest : public PapyrusFileSystemTest {};

TEST_F(ListingFilesTest, EmptyFolder) {
    const auto folder = MkDir("Hello");

    const auto results = PapyrusFileSystem::List(nullptr, folder);

    EXPECT_EQ(results.size(), 0);
}

TEST_F(ListingFilesTest, OneFile) {
    const auto folder = MkDir("Hello");
    const auto file = Touch("Hello\\Test.txt");
    
    const auto results = PapyrusFileSystem::List(nullptr, folder);

    EXPECT_EQ(results.size(), 1);
    EXPECT_EQ(results[0], file);
}

TEST_F(ListingFilesTest, DoesNotExist) {
    const auto results = PapyrusFileSystem::List(nullptr, "C:\\This\\Does\\Not\\Exist");

    EXPECT_EQ(results.size(), 0);
}

// TEST_F(ListingFilesTest, OnlyListFolders) {
//     EXPECT_TRUE(false);
// }

// TEST_F(ListingFilesTest, OnlyListFiles) {
//     EXPECT_TRUE(false);
// }

// TEST_F(ListingFilesTest, OnlyListFilesWithExtension) {
//     EXPECT_TRUE(false);
// }

// TEST_F(ListingFilesTest, OnlyListEntriesContainingText) {
//     EXPECT_TRUE(false);
// }

// TEST_F(ListingFilesTest, OnlyListEntriesMatchingRegexString) {
//     EXPECT_TRUE(false);
// }

// TEST_F(ListingFilesTest, ListRecursiveEntries) {
//     EXPECT_TRUE(false);
// }

// TEST_F(ListingFilesTest, ListRecursiveEntriesToProvidedDepth) {
//     EXPECT_TRUE(false);
// }
