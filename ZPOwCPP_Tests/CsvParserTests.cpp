
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../ZPOwCPP_Main/csvparser.h"

using namespace testing;

TEST(CsvParserTests, ctorTest)
{
    std::string separator = ",";
    CsvParser csvParser(separator);
    EXPECT_EQ(separator, csvParser.getSeparator());
}

TEST(CsvParserTests, basicParseTest)
{
    std::string text = "Speed,Course,Accuracy";
    CsvParser csvParser(",");

    EXPECT_EQ((std::vector<std::string>{"Speed", "Course", "Accuracy"}), csvParser.parseLine(text));

    //text = "0.00166,0.0002,-1.00566,-0.00884,0.01254,-1.00555,51.2728665489703,22.5443017110229,\"2015-01-24 09:29:06,053\",0,0,0";
}

TEST(CsvParserTests, parseTestWithQuotes)
{
    std::string text = "0.00166,0.0002,-1.00566,-0.00884,0.01254,-1.00555,51.2728665489703,22.5443017110229,\"2015-01-24 09:29:06,053\",0,0,0";
    CsvParser csvParser(",");

    EXPECT_EQ((std::vector<std::string>{"0.00166","0.0002","-1.00566","-0.00884","0.01254","-1.00555","51.2728665489703","22.5443017110229","\"2015-01-24 09:29:06,053\"","0","0","0"}), csvParser.parseLine(text));
}
