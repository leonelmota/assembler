#include <vector>
#include <string>
#include "symbol.h"

using namespace std;

Symbol::Symbol(string symbol, int value)
{
    this->symbol = symbol;
    this->value = value;
}