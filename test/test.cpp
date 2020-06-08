#include "menu.h"
#include "wordsTranslate.h"

#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>

void fillVector(
        std::vector<std::pair<std::string, std::string>>& vector,
        std::string text)
{
    std::pair<std::string, std::string> pair;
    pair.first = text;
    vector.push_back(pair);
}

TEST(answerCheckTest, correct)
{
    std::vector<std::pair<std::string, std::string>> vector;
    std::string answer;
    int index = 0;

    answer = "Test";
    fillVector(vector, answer);
    EXPECT_TRUE(answerCheck(answer, vector, index));
    vector.clear();

    answer = "Airplane";
    fillVector(vector, answer);
    EXPECT_TRUE(answerCheck(answer, vector, index));
    vector.clear();

    answer = "Suitcase";
    fillVector(vector, answer);
    EXPECT_TRUE(answerCheck(answer, vector, index));
    vector.clear();

    answer = "Economics";
    fillVector(vector, answer);
    EXPECT_TRUE(answerCheck(answer, vector, index));
    vector.clear();

    answer = "Chemistry";
    fillVector(vector, answer);
    EXPECT_TRUE(answerCheck(answer, vector, index));
    vector.clear();
}

TEST(answerCheckTest, incorrect)
{
    std::vector<std::pair<std::string, std::string>> vector;
    std::string answer;
    int index = 0;

    answer = "qwerty";
    fillVector(vector, "Test");
    EXPECT_FALSE(answerCheck(answer, vector, index));
    vector.clear();

    answer = "oirplane";
    fillVector(vector, "Airplane");
    EXPECT_FALSE(answerCheck(answer, vector, index));
    vector.clear();

    answer = "suitcase";
    fillVector(vector, "Suitcase");
    EXPECT_FALSE(answerCheck(answer, vector, index));
    vector.clear();

    answer = "Eeconomics";
    fillVector(vector, "Economics");
    EXPECT_FALSE(answerCheck(answer, vector, index));
    vector.clear();

    answer = "chomistry";
    fillVector(vector, "Chemistry");
    EXPECT_FALSE(answerCheck(answer, vector, index));
    vector.clear();
}