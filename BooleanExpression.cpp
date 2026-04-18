#include "BooleanExpression.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// constructor
BooleanExpression::BooleanExpression(string text)
{
    expression = text;

    // make uppercase
    for (int i = 0; i < expression.length(); i++)
    {
        expression[i] = toupper(expression[i]);
    }
}

// return expression
string BooleanExpression::getExpression()
{
    return expression;
}

// make columns for table
vector<string> BooleanExpression::getSteps()
{
    vector<string> steps;

    steps.push_back("A");
    steps.push_back("B");
    steps.push_back("C");

    // check NOT
    if (expression.find("NOT A") != string::npos)
        steps.push_back("NOT A");

    if (expression.find("NOT B") != string::npos)
        steps.push_back("NOT B");

    if (expression.find("NOT C") != string::npos)
        steps.push_back("NOT C");

    // final expression
    steps.push_back(expression);

    return steps;
}

// priority of operator
int getLevel(string op)
{
    if (op == "NOT")
        return 3;

    if (op == "AND" || op == "NAND")
        return 2;

    if (op == "XOR")
        return 2;

    if (op == "OR" || op == "NOR")
        return 1;

    return 0;
}

// check operator
bool isOp(string text)
{
    if (text == "AND") return true;
    if (text == "OR") return true;
    if (text == "NOT") return true;
    if (text == "XOR") return true;
    if (text == "NAND") return true;
    if (text == "NOR") return true;

    return false;
}

// evaluate each row
bool BooleanExpression::evaluate(bool A, bool B, bool C, string step)
{
    // easy columns first
    if (step == "A") return A;
    if (step == "B") return B;
    if (step == "C") return C;

    if (step == "NOT A") return !A;
    if (step == "NOT B") return !B;
    if (step == "NOT C") return !C;

    // split words
    stringstream ss(step);
    vector<string> words;
    string temp;

    while (ss >> temp)
    {
        words.push_back(temp);
    }

    // convert to postfix
    vector<string> output;
    stack<string> ops;

    for (int i = 0; i < words.size(); i++)
    {
        string now = words[i];

        if (now == "A" || now == "B" || now == "C")
        {
            output.push_back(now);
        }
        else if (isOp(now))
        {
            while (!ops.empty())
            {
                if (getLevel(ops.top()) >= getLevel(now))
                {
                    output.push_back(ops.top());
                    ops.pop();
                }
                else
                {
                    break;
                }
            }

            ops.push(now);
        }
    }

    while (!ops.empty())
    {
        output.push_back(ops.top());
        ops.pop();
    }

    // Solve the postfixx
    stack<bool> values;

    for (int i = 0; i < output.size(); i++)
    {
        string now = output[i];

        if (now == "A")
            values.push(A);

        else if (now == "B")
            values.push(B);

        else if (now == "C")
            values.push(C);

        else if (now == "NOT")
        {
            bool x = values.top();
            values.pop();

            values.push(!x);
        }
        else
        {
            bool second = values.top();
            values.pop();

            bool first = values.top();
            values.pop();

            if (now == "AND")
                values.push(first && second);

            else if (now == "OR")
                values.push(first || second);

            else if (now == "XOR")
                values.push(first != second);

            else if (now == "NAND")
                values.push(!(first && second));

            else if (now == "NOR")
                values.push(!(first || second));
        }
    }

    return values.top();
}