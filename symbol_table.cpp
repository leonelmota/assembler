#include "symbol_table.h"
#include <vector>

SymbolTable::SymbolTable()
{
}

void SymbolTable::insert(Symbol new_symbol)
{
    table.push_back(new_symbol);
}

int SymbolTable::find(string operand)
{
    int ret = -1;
    for (auto symbol : table) {
	if (symbol.symbol == operand)
	ret = symbol.value;
    }
    return ret;
}
