#include <iostream>
#include <string>
#include <vector>
#include "instruction.h"
#include "symbol.h"

using namespace std;

#define MAX_INPUT_SIZE 1000
#define MAX_TOKEN_SIZE 6
#define MEMORY_SIZE 1000
#define MAX_INSTRUCTIONS 10000

vector<int> memory(MEMORY_SIZE);
int PC, AC, SP, ILC;
vector<Instruction> instructions;
vector<Symbol> symbol_table;

void read_instructions();

void pass_one();

void pass_two();

void process_instruction(const Instruction &instruction);

void load(const Instruction &instruction);

void store(const Instruction &instruction);

void add(const Instruction &instruction);

void sub(const Instruction &instruction);

void jmp(const Instruction &instruction);

void jpg(const Instruction &instruction);

void jpl(const Instruction &instruction);

void jpe(const Instruction &instruction);

void jpne(const Instruction &instruction);

void push(const Instruction &instruction);

void pop(const Instruction &instruction);

void read(const Instruction &instruction);

void write(const Instruction &instruction);

void call(const Instruction &instruction);

void ret(const Instruction &instruction);

void halt(const Instruction &instruction);

int main()
{

    read_instructions();

    pass_one();

    pass_two();

    return 0;
}

void read_instructions()
{
    while (true)
    {
        string input;
        getline(cin, input);
        if (input == "END")
            break;

        instructions.push_back(Instruction(input));
    }
}

void pass_one()
{
    for (auto instruction : instructions)
    {
        cout << instruction.operator_str << ' ' << instruction.operator_code << ' ' << instruction.operand << endl;
    }
}

void pass_two()
{
    for (auto instruction : instructions)
    {
    }
}
