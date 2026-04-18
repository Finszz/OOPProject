#ifndef BOOLEAN_OPERATOR_H
#define BOOLEAN_OPERATOR_H

using namespace std;

class BooleanOperator {
public:
    virtual bool apply(bool a, bool b = false) = 0;
};

class AND : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

class OR : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

class NOT : public BooleanOperator {
public:
    bool apply(bool a, bool b = false);
};

class XOR : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

class NAND : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

class NOR : public BooleanOperator {
public:
    bool apply(bool a, bool b);
};

#endif