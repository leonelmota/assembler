#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define True 1
#define False 0

#define MAX_INPUT_SIZE 1000
#define MAX_TOKEN_SIZE 6
#define MEMORY_SIZE 1000
#define MAX_INSTRUCTIONS 10000

enum Operator {LOAD = 1, STORE = 2, ADD = 3, SUB = 4, JMP = 5, JPG = 6, JPL = 7,
               JPE = 8, JPNE = 9, PUSH = 10, POP = 11, READ = 12, WRITE = 13,
               CALL = 14, RET = 15, HALT = 16};

struct Instruction{
    char *label;
    char *operator_str;
    enum Operator operator_code;
    char *operand;
    int size;
};

struct Symbol {
    char *symbol;
    int value;
};

int memory[MEMORY_SIZE];
int PC, AC, SP, ILC, num_instructions;
// não é a melhor solução alocar estaticamente as tabelas, pode dar overflow ou usar gastar memoria a toa
struct Instruction instructions[MAX_INSTRUCTIONS]; 
struct Symbol symbol_table[MAX_INSTRUCTIONS];

void read_instructions();

void pass_one();

void pass_two();

void process_string(const char* input, int idx);

void process_instruction(const struct Instruction *instruction);

void load(const struct Instruction *instruction);

void store(const struct Instruction *instruction);

void add(const struct Instruction *instruction);

void sub(const struct Instruction *instruction);

void jmp(const struct Instruction *instruction);

void jpg(const struct Instruction *instruction);

void jpl(const struct Instruction *instruction);

void jpe(const struct Instruction *instruction);

void jpne(const struct Instruction *instruction);

void push(const struct Instruction *instruction);

void pop(const struct Instruction *instruction);

void read(const struct Instruction *instruction);

void write(const struct Instruction *instruction);

void call(const struct Instruction *instruction);

void ret(const struct Instruction *instruction);

void halt(const struct Instruction *instruction);

int main(){

    read_instructions();

    pass_one();

    pass_two();


    return 0;
}

void read_instructions(){
    for(int i=0; i<MAX_INSTRUCTIONS; i++){
        char input[MAX_INPUT_SIZE];

        fgets(input, MAX_INPUT_SIZE-1, stdin);
        
        // falta tratar pseudo instruções
        process_string(input, i);
        
        if(strcmp(instructions[i].operator_str, "END") != 0){ // strcmp retorna 0 quando strings são iguais
            num_instructions = i;
            break;
        }
    }
}

void pass_one(){
    for (int i=0; i<num_instructions; i++){

    }
}

void pass_two(){
    for (int i=0; i<num_instructions; i++){

    }
}

void process_string(const char* input, int idx){
    char input_cpy[MAX_INPUT_SIZE];
    strcpy(input_cpy, input);
    char *token = strtok(input_cpy, " ");
    if (token[strlen(token)-1] == ':'){  
        strncpy(instructions[idx].label, token, strlen(token)-1);
        token = strtok(NULL, " ");  // pega o próximo token 
    }
    strcpy(instructions[idx].operator_str, token);
    token = strtok(NULL, " "); 
    strcpy(instructions[idx].operand, token);
    instructions[idx].operator_code = get_opcode(instructions[idx].operator_str);

    return;
}


enum Operator get_opcode(const char* operator_str){
    if (strcmp(operator_str, "LOAD") != 0){
        return LOAD;
    }
    else if (strcmp(operator_str, "STORE") != 0){
        return STORE;
    }
    else if (strcmp(operator_str, "ADD") != 0){
        return ADD;
    }
    else if (strcmp(operator_str, "SUB") != 0){
        return SUB;
    }
    else if (strcmp(operator_str, "JMP") != 0){
        return JMP;
    }
    else if (strcmp(operator_str, "JPG") != 0){
        return JPG;
    }
    else if (strcmp(operator_str, "JPL") != 0){
        return JPL;
    }
    else if (strcmp(operator_str, "JPE") != 0){
        return JPE;
    }
    else if (strcmp(operator_str, "JPNE") != 0){
        return JPNE;
    }
    else if (strcmp(operator_str, "PUSH") != 0){
        return PUSH;
    }
    else if (strcmp(operator_str, "POP") != 0){
        return POP;
    }
    else if (strcmp(operator_str, "READ") != 0){
        return READ;
    }
    else if (strcmp(operator_str, "WRITE") != 0){
        return WRITE;
    }
    else if (strcmp(operator_str, "CALL") != 0){
        return CALL;
    }
    else if (strcmp(operator_str, "RET") != 0){
        return RET;
    }
    else if (strcmp(operator_str, "HALT") != 0){
        return HALT;
    }
}
