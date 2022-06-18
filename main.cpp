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
	ILC = 0;
	for (auto instruction : instructions)
	{ 
		//cout << instruction.operator_str << ' ' << instruction.operator_code << ' ' << instruction.operand << endl;

		if (instruction.label != "") 
			symbol_table.insert(Symbol(instruction.label, ILC));
		if (instruction.is_pseudo) // pseudo instrução WORD
		{
			// determinar espaço para dados
		}
		else
		{
			// pesquisar tabela de operandos 
			// (ja sabemos o operando, entao acho que nao precisa)
			// processar literais (acho que não precisa)
		}

		ILC += instruction.size;
	}
}

void pass_two()
{
	int size = ILC;
	ILC = 0;
	cout << "MVI ";
	cout << ILC << ' ';
	cout << MEMORY_SIZE -1 << ' ';
	cout << size << ' ';

	for (auto instruction : instructions)
	{
		if (!instruction.is_pseudo)
			process_instruction(instruction);

		// output
		if (!instruction.is_pseudo) {
			cout << instruction.operator_code << ' ';

			if (instruction.size > 1) {
				int location = symbol_table.find(instruction.operand);
				cout << location - ILC << ' ';
			}
		}
		else
			cout << 0 << ' ';
		ILC += instruction.size;
	}
	cout << endl;
}

void process_instruction(const Instruction &instruction)
{
	switch (instruction.operator_code)
	{
		case LOAD:
			load(instruction);
			break;
		case STORE:
			store(instruction);
			break;
		case ADD:
			add(instruction);
			break;
		case SUB:
			sub(instruction);
			break;
		case JMP:
			jmp(instruction);
			break;
		case JPG:
			jpg(instruction);
			break;
		case JPL:
			jpl(instruction);
			break;
		case JPE:
			jpe(instruction);
			break;
		case JPNE:
			jpne(instruction);
			break;
		case PUSH:
			push(instruction);
			break;
		case POP:
			pop(instruction);
			break;
		case READ:
			read(instruction);
			break;
		case WRITE:
			write(instruction);
			break;
		case CALL:
			call(instruction);
			break;
		case RET:
			ret(instruction);
			break;
		case HALT:
			halt(instruction);
			break;
		default:
			break;
	}
}

void load(const Instruction &instruction) {}

void store(const Instruction &instruction) {}

void add(const Instruction &instruction) {}

void sub(const Instruction &instruction) {}

void jmp(const Instruction &instruction) {}

void jpg(const Instruction &instruction) {}

void jpl(const Instruction &instruction) {}

void jpe(const Instruction &instruction) {}

void jpne(const Instruction &instruction) {}

void push(const Instruction &instruction) {}

void pop(const Instruction &instruction) {}

void read(const Instruction &instruction) {}

void write(const Instruction &instruction) {}

void call(const Instruction &instruction) {}

void ret(const Instruction &instruction) {}

void halt(const Instruction &instruction) {}


