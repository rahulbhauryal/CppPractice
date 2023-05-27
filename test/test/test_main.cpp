#include <gtest/gtest.h>

// Test case 1: Check if two integers are equal
TEST(EqualityTest, Integers) {
    int a = 5;
    int b = 5;
    ASSERT_EQ(a, b);
}

// Test case 2: Check if a string is empty
TEST(EmptyTest, String) {
    std::string str;
    EXPECT_TRUE(str.empty());
}

// Test case 3: Check if a value is within a specific range
TEST(RangeTest, Value) {
    int value = 10;
    EXPECT_GE(value, 5);
    EXPECT_LE(value, 15);
}

// Test case 4: Check if a vector contains a specific element
TEST(VectorTest, ContainsElement) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int element = 3;
    EXPECT_TRUE(std::find(vec.begin(), vec.end(), element) != vec.end());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

