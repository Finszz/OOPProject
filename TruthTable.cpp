#include "TruthTable.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

TruthTable::TruthTable(BooleanExpression inputTT) : express(inputTT) {}


// show truth table
void TruthTable::generate() {

    vector<string> steps = express.getSteps();

    cout << "\nTruth Table:\n\n";

    // print header
    for (int i = 0; i < steps.size(); i++) {
        cout << "| " << setw(12) << left << steps[i] << " ";
    }
    cout << "|\n";

    // line
    for (int i = 0; i < steps.size(); i++) {
        cout << "---------------";
    }
    cout << "-\n";


    // rows (000 to 111)
    for (int n = 0; n < 8; n++) {

        bool A = (n & 4);
        bool B = (n & 2);
        bool C = (n & 1);

        for (int i = 0; i < steps.size(); i++) {

            bool result = express.evaluate(A, B, C, steps[i]);

            cout << "| " << setw(12) << left << result << " ";
        }

        cout << "|\n";
    }
}



// save file
void TruthTable::save(string filename) {

    ofstream file(filename + ".txt");

    vector<string> steps = express.getSteps();

    // header
    for (int i = 0; i < steps.size(); i++) {
        file << "| " << setw(12) << left << steps[i] << " ";
    }
    file << "|\n";

    for (int i = 0; i < steps.size(); i++) {
        file << "---------------";
    }
    file << "-\n";


    // rows
    for (int n = 0; n < 8; n++) {

        bool A = (n & 4);
        bool B = (n & 2);
        bool C = (n & 1);

        for (int i = 0; i < steps.size(); i++) {

            bool result = express.evaluate(A, B, C, steps[i]);

            file << "| " << setw(12) << left << result << " ";
        }

        file << "|\n";
    }

    file.close();

    cout << "\nSaved successfully.\n";
}