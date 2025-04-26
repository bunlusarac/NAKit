#include <gtest/gtest.h>
#include <NAKit.h>

TEST(SquareTest, PositiveNumbers) {
    EXPECT_EQ(Square(2.0), 4.0);
    EXPECT_EQ(Square(3.0), 9.0);
    EXPECT_EQ(Square(4.0), 16.0);
}