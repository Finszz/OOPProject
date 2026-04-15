#ifndef BOOLEAN_EXPRESSION_H
#define BOOLEAN_EXPRESSION_H

#include <string>
using namespace std;

class BooleanExpression {
private:
    string expr;

public:
    BooleanExpression(string code);

    void explainOperators();

    bool evaluate(bool A, bool B, bool C);
};

#endif