
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../ZPOwCPP_Main/menu.h"

using namespace testing;

TEST(MenuTestSuite, Ctor)
{
    Menu menu("h");
    EXPECT_EQ("h", menu.getPromptText());
}

