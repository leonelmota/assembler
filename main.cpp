#include <iostream>
#include <string>
#include <vector>
#include "instruction.h"
#include "symbol.h"
#include "symbol_table.h"

using namespace std;

#define MEMORY_SIZE 1000

vector<int> memory(MEMORY_SIZE);
int PC, AC, SP, ILC = 0;
vector<Instruction> instructions;
SymbolTable symbol_table;

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

        if (instruction.label != "")
        {
            symbol_table.insert(Symbol(instruction.label, ILC));
        }
        if (instruction.is_pseudo) // pseudo instrução WRITE
        {
            // determinar espaço para dados
        }
        else
        {
            // pesquisar tabela de operandos
            // obter tamanho da instrução
            // processar literais
        }

        ILC += instruction.size;
    }
}

void pass_two()
{
    for (auto instruction : instructions)
    {
    }
}
