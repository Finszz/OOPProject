#ifndef TRUTH_TABLE_H
#define TRUTH_TABLE_H

#include "BooleanExpression.h"
#include <string>
using namespace std;

class TruthTable {
private:
    BooleanExpression express;

public:
    TruthTable(BooleanExpression express);

    void generate();

    void save(string filename);
};

#endif