/*************************************************************************
Description: Program to create a stack by pushing and poping integers,
and print stack values
Author: Jose Neyra
**************************************************************************/

// Stack_Integers.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

//Struct declaration
struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

//Struct variables declaration
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

//Stack Function Prototypes:
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions();

// Main function
int main()
{
	StackNodePtr stackPtr = NULL;
	int value;

	instructions();
	printf_s("%s", "? ");
	unsigned int choice;
	scanf_s("%u", &choice);

	while (choice != 3) {
		switch (choice) {
		case 1:
			printf_s("%s", "Enter an integer: ");
			scanf_s("%d", &value);
			push(&stackPtr, value);
			printStack(stackPtr);
			break;
		case 2:
			if (!isEmpty(stackPtr)) {
				printf_s("The popped values is %d.\n", pop(&stackPtr));
			}

			printStack(stackPtr);
			break;
		default:
			printf_s("Invalid choice.\n");
			instructions();
			break;
		}//end switch
		printf_s("%s", "? ");
		scanf_s("%u", &choice);
	}
	printf_s("End of run.\n");
}

//Instructions function
void instructions() {
	printf_s("Enter a choice:\n");
	printf_s("1 to push a value on the stack.\n");
	printf_s("2 to pop a value off the stack.\n");
	printf_s("3 to end program.\n");
}

//Push to stack function
void push(StackNodePtr *topPtr, int info) {
	StackNodePtr newPtr = malloc(sizeof(StackNode));
	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else {
		printf("%d not inserted. No memory available.\n", info);
	}
}
//Pop from stack function
int pop(StackNodePtr *topPtr) {
	StackNodePtr tempPtr = *topPtr;
	char popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;
}

//Empty stack NULL return
int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}

//Print values in Stack
void printStack(StackNodePtr currentPtr) {
	if (currentPtr == NULL) {
		printf_s("The stack is empty.\n");
	}
	else {
		printf_s("The stack is:");
		while (currentPtr != NULL) {
			printf_s("%d-->", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf_s("NULL\n");
	}
}
