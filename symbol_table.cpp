#include "symbol_table.h"
#include <vector>

SymbolTable::SymbolTable()
{
}

void SymbolTable::insert(Symbol new_symbol)
{
    table.push_back(new_symbol);
}