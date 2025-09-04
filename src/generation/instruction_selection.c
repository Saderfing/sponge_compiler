#include "instruction_selection.h"

InstructionName operatorToInstruction(Operator op){
	switch (op){
		case SO_ADD:
			return SI_ADD;

		case SO_SUB:
			return SI_SUB;

		case SO_MUL:
			return SI_MUL;
	
		case SO_LSL:
			return SI_LSL;
	
		case SO_LSR:
			return SI_LSR;

		case SO_AFF:
			return SI_MOV;

		default:
			fatalError("Unsupported Operator", -1);
	}
	return SI_UNKOWN;
}

// void handleOperatorNode(ASTNode *node, InstStream *is){
// 	Instruction inst;
// 	emptyInstruction(&inst);
// 	InstructionName isName = operatorToInstruction(GET_VARIABLE_NAME(node));
// }


// Variable ASTToInstStreamRec(ASTNode *node, InstStream *is){
// 	switch (node->nodeType){
// 	case ST_CTX:
// 		break;
	
// 	case ST_OPE:
// 		if ( node->childCount != 2){
// 			fatalError("Only binary operators are supported", -1);
// 		}

// 		handleOperatorNode(node, is);
// 		break;

// 	case ST_CST:
// 		char name[10];
// 		snprintf(name, 10, "%lu", GET_CONSTANT_VALUE(node) );
// 		Variable v = newVariable(name, NEW_INT(), true, GET_CONSTANT_VALUE(node) );
// 		Instruction instr = newInstruction(SI_MOV, name, );

// 		return;
	
// 	default:
// 		break;
// 	}


// }

// void ASTToInstStream(ASTNode *root){
// 	InstStream *is = newInstStream();
// 	ASTToInstStreamRec(root, is);
// 	return is;
// }