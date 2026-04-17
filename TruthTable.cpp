#include "TruthTable.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

TruthTable::TruthTable(BooleanExpression logic) : expr(logic) {}

void TruthTable::generate() {
    cout << "\nTruth Table:\n";
    cout << "|A|B|C|NOT A|NOT B|NOT C|A AND B|A AND C|B AND C|A OR B|A OR C|B OR C|result|\n";
    for (int i = 0; i < 8; i++) {
        bool A = (i & 4) != 0;
        bool B = (i & 2) != 0;
        bool C = (i & 1) != 0;
        bool notA = !A;
        bool notB = !B;
        bool notC = !C;
        bool aandb = A && B;
        bool aandc = A && C;
        bool bandc = B && C;
        bool aorb = A || B;
        bool aorc = A || C;
        bool borc = B || C;
        bool result = expr.evaluate(A, B, C);
        cout << "|" << A << "|" << B << "|" << C << "|" << notA << "|" << notB << "|" << notC << "|" << aandb << "|" << aandc << "|" << bandc << "|" << aorb << "|" << aorc << "|" << borc << "|" << result << "|\n";
    }
}

void TruthTable::save(string filename, string expression) {
    ofstream file(filename + ".txt");
    file << "Expression: " << expression << "\n\n";
    file << "|A|B|C|NOT A|NOT B|NOT C|A AND B|A AND C|B AND C|A OR B|A OR C|B OR C|result|\n";
    for (int i = 0; i < 8; i++) {
        bool A = (i & 4) != 0;
        bool B = (i & 2) != 0;
        bool C = (i & 1) != 0;
        bool notA = !A;
        bool notB = !B;
        bool notC = !C;
        bool aandb = A && B;
        bool aandc = A && C;
        bool bandc = B && C;
        bool aorb = A || B;
        bool aorc = A || C;
        bool borc = B || C;
        bool result = expr.evaluate(A, B, C);
        file << "|" << A << "|" << B << "|" << C << "|" << notA << "|" << notB << "|" << notC << "|" << aandb << "|" << aandc << "|" << bandc << "|" << aorb << "|" << aorc << "|" << borc << "|" << result << "|\n";
    }
    file.close();
    cout << "Saved.\n";
}