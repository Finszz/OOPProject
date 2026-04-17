#ifndef BOOLEAN_EXPRESSION_H
#define BOOLEAN_EXPRESSION_H

#include <string>
#include <vector>
using namespace std;

class BooleanExpression {
private:
    string expr;

public:
    BooleanExpression(string logic);

    void explainOperators();

    vector<string> getSteps();

    bool evaluate(bool A, bool B, bool C);
};

#endif