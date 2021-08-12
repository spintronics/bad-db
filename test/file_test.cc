#include "../lib/file.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(FileTest, BasicAssertions)
{
    string filename = "test_disk";
    file_utils::create(filename);
    EXPECT_TRUE(file_utils::file_exists(filename));

    auto split_filename = vector<string>{"test", "disk"};

    EXPECT_EQ(file_utils::split(filename, "_"), split_filename);

    EXPECT_EQ(file_utils::join(split_filename, "_"), filename);
}