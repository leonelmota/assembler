#ifndef INCLUDE_INSTRUCTION_H
#define INCLUDE_INSTRUCTION_H

#include <string>
#include <vector>

using namespace std;

enum Operator
{
    LOAD = 1,
    STORE = 2,
    ADD = 3,
    SUB = 4,
    JMP = 5,
    JPG = 6,
    JPL = 7,
    JPE = 8,
    JPNE = 9,
    PUSH = 10,
    POP = 11,
    READ = 12,
    WRITE = 13,
    CALL = 14,
    RET = 15,
    HALT = 16,
    OTHER = 17
};

class Instruction
{
public:
    string label;
    string operator_str;
    string Operator;
    enum Operator operator_code;
    string operand;
    int size;
    bool is_pseudo;

    Instruction(string input);

private:
    enum Operator get_opcode(const string &operator_str);
};

#endif