#include "BooleanOperator.h"

// AND
bool AND::apply(bool a, bool b) {
    return a && b;
}

// OR
bool OR::apply(bool a, bool b) {
    return a || b;
}

// NOT
bool NOT::apply(bool a, bool b) {
    return !a;
}

// XOR
bool XOR::apply(bool a, bool b) {
    return a != b;
}

// NAND
bool NAND::apply(bool a, bool b) {
    return !(a && b);
}

// NOR
bool NOR::apply(bool a, bool b) {
    return !(a || b);
}