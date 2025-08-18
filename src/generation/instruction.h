#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "variable.h"

typedef enum instrName {
	SI_AND,
	SI_ORR,
	SI_XOR,
	SI_ADD,
	SI_SUB,
	SI_MUL,

	SI_LSL,
	SI_LSR,

	SI_MOV,
	SI_LDR,
	SI_STR,
	
	SI_UNKOWN,
	INSTRUCTION_COUNT
} InstructionName;

typedef struct {
	InstructionName instr;
	Variable dest;
	Variable arg0;
	Variable arg1;
}Instruction;

void emptyInstruction(Instruction *inst);

Instruction newEmptyInstruction();

Instruction newInstruction(InstructionName name, Variable dest, Variable arg0, Variable arg1);

void printInstruction(Instruction inst);

#endif