#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../ZPOwCPP_Main/algorytmy.h>

using namespace testing;

TEST(AlgorytmyTests, srednie)
{
    std::vector<double> sumy {5, 10, 15};
    EXPECT_EQ((std::vector<double>{1, 2, 3}), Algorytmy::srednie(sumy, 5));
    EXPECT_EQ(sumy, Algorytmy::srednie(sumy, 1));
}

TEST(AlgorytmyTests, mediany1)
{
    std::vector<std::vector<double>> liczby {
        {1, 2, 3},
        {4, 5, 6}
    };
    EXPECT_EQ((std::vector<double>{2.5, 3.5, 4.5}), Algorytmy::mediany(liczby));
}

TEST(AlgorytmyTests, mediany2)
{
    auto liczby = std::vector<std::vector<double>>
    {
        {1, 2, 3},
        {7, 8, 9},
        {4, 5, 6}
    };
    EXPECT_EQ((std::vector<double>{4, 5, 6}), Algorytmy::mediany(liczby));
}

TEST(AlgorytmyTests, mediany3)
{
    std::vector<std::vector<double>> liczby {
        {1, 2, 3},
        {42, 4, 5},
        {7, 8, 9},
        {6, 12, 11}
    };
    std::vector<double> oczekiwaneMediany
    {
        (6 + 7) / 2.0, (4 + 8) / 2.0, (5 + 9) / 2.0
    };
    EXPECT_EQ(oczekiwaneMediany, Algorytmy::mediany(liczby));
}

TEST(AlgorytmyTests, odchyleniaStandardowe)
{
    std::vector<std::vector<double>> wejscie
    {
        {6, 4, 3, 2},
        {12, 9, 2, 1},
        {-32, 22, -2, 14},
    };
    std::vector<double> srednieKolumn
    {
        -4.66666666666667, 11.6666666666667, 1, 5.66666666666667
    };
    std::vector<double> oczekiwaneOdchyleniaKolumn
    {
        23.8607, 9.2916, 2.6458, 7.2342
    };
    auto obliczoneOdchyleniaKolumn = Algorytmy::odchyleniaStandardowe(wejscie, srednieKolumn);
    for (unsigned int i = 0; i < srednieKolumn.size(); i++)
    {
        EXPECT_NEAR(oczekiwaneOdchyleniaKolumn[i], obliczoneOdchyleniaKolumn[i], 0.001);
    }
}
