#ifndef BOOLEAN_EXPRESSION_H
#define BOOLEAN_EXPRESSION_H

#include <string>
#include <vector>
using namespace std;

class BooleanExpression {
private:
    string expression;

public:
    BooleanExpression(string text);

    string getExpression();

    vector<string> getSteps();

    bool evaluate(bool A, bool B, bool C, string step);
};

#endif