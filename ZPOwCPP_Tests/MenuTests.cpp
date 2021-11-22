
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../ZPOwCPP_Main/menu.h"

using namespace testing;

TEST(MenuTests, ctorTest)
{
    Menu menu("h");
    EXPECT_EQ("h", menu.getPromptText());
}

TEST(MenuTests, promptTextTest)
{
    Menu menu("");
    const std::string t = "abc";
    menu.setPromptText(t);
    EXPECT_EQ(t, menu.getPromptText());
}

TEST(MenuTests, exitTextTest)
{
    Menu menu("");
    const std::string t = "abc";
    menu.setExitOptionText(t);
    EXPECT_EQ(t, menu.getExitOptionText());
}
