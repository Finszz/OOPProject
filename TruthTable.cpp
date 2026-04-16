#include "TruthTable.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

TruthTable::TruthTable(BooleanExpression logic) : expr(logic) {}

void TruthTable::generate() {

    cout << "\nTruth Table:\n";
    cout << "|A | B | C | result |\n";

    for (int i = 0; i < 8; i++) {

        bool A = (i & 4);
        bool B = (i & 2);
        bool C = (i & 1);

        bool result = expr.evaluate(A, B, C);

        cout << "| " << setw(1) << A << " | " << setw(1) << B << " | " << setw(1) << C << " | " << setw(6) << result << " |\n";
    }
}