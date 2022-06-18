#ifndef INCLUDE_SYMBOL_TABLE_H
#define INCLUDE_SYMBOL_TABLE_H

#include "symbol.h"
#include <vector>
#include <string>

using namespace std;

class SymbolTable
{
public:
    vector<Symbol> table;

    SymbolTable();
    void insert(Symbol new_symbol);
    int find(string operand);
};

#endif
