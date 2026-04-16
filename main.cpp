#include <iostream>
#include "TruthTable.h"

using namespace std;

int main() {

    cout << "Boolean Simulator\n";

    string input;
    cout << "Enter expression: ";
    getline(cin, input);

    BooleanExpression logic(input);

    logic.explainOperators();

    TruthTable table(logic);

    table.generate();

    char choice;
    cout << "\nSave? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {

        string name;
        cout << "Filename: ";
        cin >> name;

        table.save(name, input);
    }

    return 0;
}