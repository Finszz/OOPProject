#include "BooleanExpression.h"
#include "BooleanOperator.h"
#include <iostream>
#include <algorithm>

using namespace std;

BooleanExpression::BooleanExpression(string code){
    expr = code;

    // To make uppercase for easier parsing
    transform(expr.begin(), expr.end(), expr.begin(), ::toupper);
}

void BooleanExpression::explainOperators() {

    cout << "\nOperators used:\n";

    if (expr.find("AND") != string::npos)
        cout << "AND: both must be true\n";

    if (expr.find("OR") != string::npos)
        cout << "OR: at least one true\n";

    if (expr.find("NOT") != string::npos)
        cout << "NOT: reverse value\n";

    if (expr.find("XOR") != string::npos)
        cout << "XOR: different inputs\n";

    if (expr.find("NAND") != string::npos)
        cout << "NAND: not AND\n";

    if (expr.find("NOR") != string::npos)
        cout << "NOR: not OR\n";
}

bool BooleanExpression::evaluate(bool A, bool B, bool C) {
    string exp = expr;
    exp.erase(remove(exp.begin(), exp.end(), ' '), exp.end());
    transform(exp.begin(), exp.end(), exp.begin(), ::toupper);

    size_t pos = 0;
    function<bool()> parseExpr;
    function<bool()> parseXorNorOr;
    function<bool()> parseAndNand;
    function<bool()> parseNot;
    function<bool()> parseFactor;

    auto getVar = [&](char var) {
        if (var == 'A') return A;
        if (var == 'B') return B;
        if (var == 'C') return C;
        return false;
    };
}