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
		ILC += instruction.size;

		// output
		if (!instruction.is_pseudo) {
			cout << instruction.operator_code << ' ';

			if (instruction.size > 1) {
				int location = symbol_table.find(instruction.operand);
				cout << location - ILC << ' ';
			}
		}
        else if (instruction.operator_str == "WORD")
            cout << instruction.operand << ' ';
	}
	cout << endl;
}


