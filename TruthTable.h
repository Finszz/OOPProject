#ifndef TRUTH_TABLE_H
#define TRUTH_TABLE_H

#include "BooleanExpression.h"
#include <string>
using namespace std;

class TruthTable {
private:
    BooleanExpression expr;

public:
    TruthTable(BooleanExpression logic);

    void generate();

    void save(string filename, string expression);
};

#endif