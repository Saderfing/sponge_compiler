#include "instruction.h"
#include <errno.h>


static const char *instRepr[INSTRUCTION_COUNT] = {"AND", "ORR", "XOR", "ADD", "SUB", "MUL", "DIV", "REM", "LSL", "LSR"};

void emptyInstruction(Instruction *inst){
	inst->instr  = SI_UNKOWN;
	inst->dest   = newEmptyVariable(NULL);
	inst->arg0   = newEmptyVariable(NULL);
	inst->arg1   = newEmptyVariable(NULL);
}

Instruction newEmptyInstruction(){
	Instruction inst;
	inst.instr  = SI_UNKOWN;
	inst.dest   = newEmptyVariable(NULL);
	inst.arg0   = newEmptyVariable(NULL);
	inst.arg1   = newEmptyVariable(NULL);
	return inst;
}

Instruction newInstruction(InstructionName name, Variable dest, Variable arg0, Variable arg1){
	Instruction inst;
	inst.instr = name;
	inst.dest  = dest;
	inst.arg0  = arg0;
	inst.arg1  = arg1;
	return inst;
}

void printInstruction(Instruction inst){
	printf("%u %s %s %s\n", inst.instr, inst.dest.name, inst.arg0.name, inst.arg1.name);
}
