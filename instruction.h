#include <string>
#include <vector>

using namespace std;

enum Operator
{
    LOAD = 1,
    STORE = 2,
    ADD = 3,
    SUB = 4,
    JMP = 5,
    JPG = 6,
    JPL = 7,
    JPE = 8,
    JPNE = 9,
    PUSH = 10,
    POP = 11,
    READ = 12,
    WRITE = 13,
    CALL = 14,
    RET = 15,
    HALT = 16,
    OTHER = 17
};

class Instruction
{
public:
    string label;
    string operator_str;
    string Operator;
    enum Operator operator_code;
    string operand;
    int size;

    vector<string> split(string s, string delimiter)
    {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
        {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }

    Instruction(string input)
    {
        vector<string> input_split = split(input, " ");

        if (input_split.size() == 3)
        {
            label = input_split[0].substr(0, input_split[0].size() - 1);
            operator_str = input_split[1];
            operand = input_split[2];
        }
        else if (input_split.size() == 2)
        {
            operator_str = input_split[0];
            operand = input_split[1];
        }
        operator_code = get_opcode(operator_str);
    }

    enum Operator get_opcode(const string &operator_str)
    {
        if (operator_str == "LOAD")
            return LOAD;
        else if (operator_str == "STORE")
            return STORE;
        else if (operator_str == "ADD")
            return ADD;
        else if (operator_str == "SUB")
            return SUB;
        else if (operator_str == "JMP")
            return JMP;
        else if (operator_str == "JPG")
            return JPG;
        else if (operator_str == "JPL")
            return JPL;
        else if (operator_str == "JPE")
            return JPE;
        else if (operator_str == "JPNE")
            return JPNE;
        else if (operator_str == "PUSH")
            return PUSH;
        else if (operator_str == "POP")
            return POP;
        else if (operator_str == "READ")
            return READ;
        else if (operator_str == "WRITE")
            return WRITE;
        else if (operator_str == "CALL")
            return CALL;
        else if (operator_str == "RET")
            return RET;
        else if (operator_str == "HALT")
            return HALT;
        else
            return OTHER;
    }
};