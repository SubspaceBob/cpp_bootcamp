#include <gtest/gtest.h>
#include "shape.h"
#include "comp_func.h"

TEST(myshapes, circle)
{
    Circle *small_circle = new Circle(5);
    Circle *large_circle = new Circle(6);

    ASSERT_TRUE(small_circle == large_circle);

    delete small_circle, large_circle;
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}