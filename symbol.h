#include <vector>
#include <string>

using namespace std;

class Symbol
{
    string symbol;
    int value;

    Symbol(string symbol, int value)
    {
        this->symbol = symbol;
        this->value = value;
    }
};