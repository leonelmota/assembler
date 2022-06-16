#ifndef INCLUDE_SYMBOL_H
#define INCLUDE_SYMBOL_H

#include <vector>
#include <string>

using namespace std;

class Symbol
{
public:
    string symbol;
    int value;

    Symbol(string symbol, int value);
};

#endif