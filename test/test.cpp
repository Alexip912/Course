#include "menu.h"
#include "wordsTranslate.h"

#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>

#define RIGHT_PATH "Topics/Test.txt"
#define WRONG_PATH "Topics/test.jpg"
#define TEST_PATH "Topics/Test.txt"

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

TEST(checkPathTest, correct)
{
    EXPECT_TRUE(checkPath(RIGHT_PATH));
}

TEST(checkPathTest, incorrect)
{
    EXPECT_FALSE(checkPath(WRONG_PATH));
}

TEST(fileParseTest, correct)
{
    std::vector<std::pair<std::string, std::string>> vector;
    fileParse(TEST_PATH, vector);

    ASSERT_STREQ(vector[0].first.c_str(), "Airoport");
    ASSERT_STREQ(vector[0].second.c_str(), "аэропорт");
    ASSERT_STREQ(vector[1].first.c_str(), "Airplane");
    ASSERT_STREQ(vector[1].second.c_str(), "самолет");
    ASSERT_STREQ(vector[2].first.c_str(), "Aisle");
    ASSERT_STREQ(vector[2].second.c_str(), "проход");
}