#include <iostream>
#include "TruthTable.h"

using namespace std;

int main() {

    cout << "BOOLEAN TRUTH TABLE SIMULATOR\n\n";

    string input;

    cout << "Enter Boolean Expression:\n";
    getline(cin, input);

    cout << "\nOperators Detected and Explained:\n";

    if (input.find("AND") != string::npos)
    {
    cout << "- AND : True only if both inputs are true.\n";
    }

    if (input.find("OR") != string::npos)
    {
    cout << "- OR  : True if at least one input is true.\n";
    }

    if (input.find("NOT") != string::npos)
    {
    cout << "- NOT : Inverts the input.\n";
    }

    if (input.find("XOR") != string::npos)
    {   
    cout << "- XOR : True if both inputs are different.\n";
    }

    if (input.find("NAND") != string::npos)
    {
    cout << "- NAND: Opposite of AND.\n";
    }

    if (input.find("NOR") != string::npos)
    {
    cout << "- NOR : Opposite of OR.\n";
    }

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