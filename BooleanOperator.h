#ifndef BOOLEAN_OPERATOR_H
#define BOOLEAN_OPERATOR_H

#include <string>
using namespace std;

// base class
class BooleanOperator {
public:
    virtual bool apply(bool a, bool b = false) = 0;
};

// AND
class AND : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

// OR
class OR : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

// NOT
class NOT : public BooleanOperator {
public:
    bool apply(bool a, bool b = false);
};

// XOR
class XOR : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

// NAND
class NAND : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

// NOR
class NOR : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

#endif