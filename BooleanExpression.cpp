#include "BooleanExpression.h"
#include "BooleanOperator.h"
#include <iostream>
#include <algorithm>

using namespace std;

BooleanExpression::BooleanExpression(string logic){
    expr = logic;

    // To make uppercase for easier parsing
    transform(expr.begin(), expr.end(), expr.begin(), ::toupper);
}

void BooleanExpression::explainOperators() {

    cout << "\nOperators used:\n";

    if (expr.find("NOT") != string::npos)
        cout << "NOT: reverse value\n";

    if (expr.find("AND") != string::npos)
        cout << "AND: both must be true\n";

    if (expr.find("OR") != string::npos)
        cout << "OR: at least one true\n";

    if (expr.find("XOR") != string::npos)
        cout << "XOR: different inputs\n";

    if (expr.find("NAND") != string::npos)
        cout << "NAND: not AND\n";

    if (expr.find("NOR") != string::npos)
        cout << "NOR: not OR\n";
}

bool BooleanExpression::evaluate(bool A, bool B, bool C) {
    string logic = expr;
    logic.erase(remove(logic.begin(), logic.end(), ' '), logic.end());
    transform(logic.begin(), logic.end(), logic.begin(), ::toupper);

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

    // Parse factor: variable or parenthesis
    parseFactor = [&]() -> bool {
        if (pos >= logic.length()) return false;
        if (logic[pos] == '(') {
            pos++;
            bool val = parseExpr();
            if (pos < logic.length() && logic[pos] == ')') pos++;
            return val;
        }
        if (logic[pos] == 'A' || logic[pos] == 'B' || logic[pos] == 'C') {
            char var = logic[pos++];
            return getVar(var);
        }
        return false;
    };

    // Parse NOT (highest precedence after parentheses)
    parseNot = [&]() -> bool {
        if (pos < logic.length() && logic.substr(pos, 3) == "NOT") {
            pos += 3;
            // Handle NOT with parentheses, for example: NOT(A)
            if (pos < logic.length() && logic[pos] == '(') {
                pos++;
                bool val = parseExpr();
                if (pos < logic.length() && logic[pos] == ')') pos++;
                return !val;
            }
            return !parseNot();
        }
        return parseFactor();
    };

    // Parse AND, NAND (next precedence)
    parseAndNand = [&]() -> bool {
        bool val = parseNot();
        while (pos < logic.length()) {
            if (logic.substr(pos, 4) == "NAND") { // check NAND before AND
                pos += 4;
                bool right = parseNot();
                val = !(val && right);
            } else if (logic.substr(pos, 3) == "AND") {
                pos += 3;
                bool right = parseNot();
                val = val && right;
            } else {
                break;
            }
        }
        return val;
    };

// Parse OR, NOR, XOR (lowest precedence)
    parseXorNorOr = [&]() -> bool {
        bool val = parseAndNand();
        while (pos < logic.length()) {
            if (logic.substr(pos, 3) == "NOR") { // check NOR before OR
                pos += 3;
                bool right = parseAndNand();
                val = !(val || right);
            } else if (logic.substr(pos, 2) == "OR") {
                pos += 2;
                bool right = parseAndNand();
                val = val || right;
            } else if (logic.substr(pos, 3) == "XOR") {
                pos += 3;
                bool right = parseAndNand();
                val = val != right;
            } else {
                break;
            }
        }
        return val;
    };

    parseExpr = parseXorNorOr;
    pos = 0;
    return parseExpr();
}
