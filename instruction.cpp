#include "instruction.h"
#include <vector>
#include <string>

using namespace std;

void ignore_comments(string &s);
vector<string> split(string s, string delimiter);

Instruction::Instruction(string input)
{
    ignore_comments(input);
    tie(label, operator_str, operand) = process_input(input);

    operator_code = get_opcode(operator_str);

    is_pseudo = operator_str == "WORD";

    size = get_intruction_size(operator_code);
}

// returns label, operator_str, operand
tuple<string, string, string> Instruction::process_input(string input)
{
    ignore_comments(input);
    if (input.find(" ") == string::npos)
        return tuple<string, string, string>("", input, "");

    vector<string> input_split = split(input, " ");

    if (input_split.size() == 3)
        return tuple<string, string, string>(input_split[0].substr(0, input_split[0].size() - 1),
                                             input_split[1],
                                             input_split[2]);
    else if (input_split.size() == 2)
        return tuple<string, string, string>("",
                                             input_split[0],
                                             input_split[1]);
    else if (input_split.size() == 1)
        return tuple<string, string, string>("", "", input_split[0]);

    else
        return tuple<string, string, string>();
}

int Instruction::get_intruction_size(enum Operator opcode)
{
    if (opcode == HALT or opcode == RET or opcode == OTHER)
        return 1;
    else
        return 2;
}

enum Operator Instruction::get_opcode(const string &op_str)
{
    if (op_str == "LOAD")
        return LOAD;
    else if (op_str == "STORE")
        return STORE;
    else if (op_str == "ADD")
        return ADD;
    else if (op_str == "SUB")
        return SUB;
    else if (op_str == "JMP")
        return JMP;
    else if (op_str == "JPG")
        return JPG;
    else if (op_str == "JPL")
        return JPL;
    else if (op_str == "JPE")
        return JPE;
    else if (op_str == "JPNE")
        return JPNE;
    else if (op_str == "PUSH")
        return PUSH;
    else if (op_str == "POP")
        return POP;
    else if (op_str == "READ")
        return READ;
    else if (op_str == "WRITE")
        return WRITE;
    else if (op_str == "CALL")
        return CALL;
    else if (op_str == "RET")
        return RET;
    else if (op_str == "HALT")
        return HALT;
    else
        return OTHER;
}

void ignore_comments(string &s)
{
    s = s.substr(0, s.find(";", 0));
}

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
