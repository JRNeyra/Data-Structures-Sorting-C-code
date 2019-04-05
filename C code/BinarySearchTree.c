/*************************************************************************************
Desription: Binary search tree code. Algorithm to search for maximum and minimum 
            integer values stored in the tree.
Author: Jose Neyra
**************************************************************************************/

// NeyraJ-BST.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct treeNode {
	struct treeNode *leftPtr;     //Pointer to left Node
	int data;
	struct treeNode *rightPtr;    //Pointer to right Node
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

//Function Prototypes
void insertNode(TreeNodePtr *treePtr, int value);   
int findSmallestBST(TreeNodePtr treePtr);
void findLargestBST(TreeNodePtr treePtr);


int main(){
	
	TreeNodePtr rootPtr = NULL;
	srand(time(NULL));
	int item;
	printf_s("Enter the number of values in the Binary search tree:\n(Enter an integer <= 15 or enter 0 to quit)\n"
		"The numbers being placed in the tree are:\n");
	scanf_s("%d", &item); 
	while (item != 0) {
		insertNode(&rootPtr, item); 
		item = rand() % 15;
		printf_s("%3d\n", item);
	}
	printf_s("\n\nThe Smallest of BST is:-- %d", findSmallestBST(rootPtr));
	printf_s("\n\nThe Largest of BST is:");
	findLargestBST(rootPtr);
}

void insertNode(TreeNodePtr *treePtr, int value) {
	if (*treePtr == NULL) {
		*treePtr = malloc(sizeof(TreeNode));
		if (*treePtr != NULL) { 
			(*treePtr)->data = value; 
			(*treePtr)->leftPtr = NULL; 
			(*treePtr)->rightPtr = NULL; 
		}
		else { printf_s("%d not inserted. No memory available.\n", value); 
		}
	}
	else {
		if(value < (*treePtr)->data) { 
			insertNode(&((*treePtr)->leftPtr), value); 
		}
		else if (value >(*treePtr)->data) { 
			insertNode(&((*treePtr)->rightPtr), value); 
		}
		else { 
			printf_s("%s\n", "dup");     
		}
	}
}

int findSmallestBST(TreeNodePtr treePtr) {     //Finding smallest number by looking on the left most node.
	
	if (treePtr == NULL) printf_s("Error: Tree is empty\n");
	while (treePtr->leftPtr != NULL) treePtr = treePtr->leftPtr;
	return treePtr->data;
}

void findLargestBST(TreeNodePtr treePtr) {     //Finding the highest number by looking in the right most node.
	
	if (treePtr == NULL) printf_s("Error: Tree is empty\n");
	while (treePtr->rightPtr != NULL) treePtr = treePtr->rightPtr;
	printf_s("-- %d\n", treePtr->data);
}
