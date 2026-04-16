#include "TruthTable.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

TruthTable::TruthTable(BooleanExpression logic) : expr(logic) {}

void TruthTable::generate() {
    cout << "\nTruth Table:\n";
    cout << "|A|B|C|result|\n";
    for (int i = 0; i < 8; i++) {
        bool A = (i & 4) != 0;
        bool B = (i & 2) != 0;
        bool C = (i & 1) != 0;
        bool result = expr.evaluate(A, B, C);
        cout << "|" << A << "|" << B << "|" << C << "|" << result << "|\n";
    }
}

void TruthTable::save(string filename, string expression) {
    ofstream file(filename + ".txt");
    file << "Expression: " << expression << "\n\n";
    file << "|A|B|C|result|\n";
    for (int i = 0; i < 8; i++) {
        bool A = (i & 4) != 0;
        bool B = (i & 2) != 0;
        bool C = (i & 1) != 0;
        bool result = expr.evaluate(A, B, C);
        file << "|" << A << "|" << B << "|" << C << "|" << result << "|\n";
    }
    file.close();
    cout << "Saved.\n";
}