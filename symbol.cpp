#include <vector>
#include <string>
#include "symbol.h"

using namespace std;

Symbol::Symbol(string symbol_, int value_)
{
    this->symbol = symbol_;
    this->value = value_;
}
