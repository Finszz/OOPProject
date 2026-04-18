#include <iostream>
#include "TruthTable.h"

using namespace std;

int main() {

    cout << "BOOLEAN TRUTH TABLE SIMULATOR\n\n";

    string input;

    cout << "Enter Boolean Expression:\n";
    getline(cin, input);

    BooleanExpression inputTT(input);

    TruthTable table(inputTT);

    table.generate();

    char choice;
    cout << "\nWould you like to save this truth table? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        string name;
        cout << "Enter filename: ";
        cin >> name;

        table.save(name);
    }

    return 0;
}