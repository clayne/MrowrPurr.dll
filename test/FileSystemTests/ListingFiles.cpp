#include "PapyrusFileSystemTests.h"

class ListingFilesTest : public PapyrusFileSystemTest {};

TEST_F(ListingFilesTest, EmptyFolder) {
    auto dir = CreateTempFolder();
    
    auto results = PapyrusFileSystem::List(nullptr, dir);

    EXPECT_EQ(results.size(), 0);
}
