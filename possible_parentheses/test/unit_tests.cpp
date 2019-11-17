#include "gtest/gtest.h"
#include "possible_parentheses.h"

void showResult(std::list<std::string> & result) {
    for (std::list<std::string>::iterator i = result.begin(); i!=result.end(); ++i) {
        printf("%s\n", (*i).c_str());
    }
};

bool isEqual(std::list<std::string> & toCheck, std::list<std::string> & answer) {
    bool returnValue = true;

    if (toCheck.size() != answer.size()) {
        returnValue = false;
        return returnValue;
    }


    while (toCheck.empty() == false) {

        if (toCheck.front() == answer.front()) {
            // Pop top of both stacks
            toCheck.pop_front();
            answer.pop_front();
        }
        else {
            returnValue = false;
            break;
        }
    }

    return returnValue;
}

TEST(test_recursive, 0) {
    std::list<std::string> result;
    possibleParenthesis(0, result);

    std::list<std::string> answer;

    ASSERT_TRUE(isEqual(result, answer));
}

TEST(test_recursive, 1) {
    std::list<std::string> result;
    possibleParenthesis(1, result);

    std::list<std::string> answer;
    answer.push_front("{}");

    ASSERT_TRUE(isEqual(result, answer));
}

TEST(test_recursive, 2) {
    std::list<std::string> result;
    possibleParenthesis(2, result);

    std::list<std::string> answer;
    answer.push_back("{}{}");
    answer.push_back("{{}}");

    ASSERT_TRUE(isEqual(result, answer));
}

TEST(test_recursive, 3) {
    std::list<std::string> result;
    possibleParenthesis(3, result);

    std::list<std::string> answer;
    answer.push_front("{}{}{}");
    answer.push_back("{}{{}}");
    answer.push_back("{{}}{}");
    answer.push_back("{{}{}}");
    answer.push_back("{{{}}}");

    ASSERT_TRUE(isEqual(result, answer));
}
