/**********************************************************************************************
HeapSort.c :
Author: Jose Neyra
Description: This is a C program that sorts any 10 element array using a heap data structure sort.
			   User must enter 10 integer values for program to sort them.
Date: 04/04/2018
***********************************************************************************************/

/*Heap sort uses reheapUp and reheapDown.     
Written by:      Date:      */
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX_ARY_SIZE 10

//    Prototype Declarations
void heapSort (int  list[ ], int last);
void reheapUp (int heap[], int newNode);
void reheapDown (int heap[], int root, int last);

int main (void){  
	// Local Declarations
	int	list[ MAX_ARY_SIZE ] = { 89, 72, 3,  15, 21, 57, 61, 44, 19, 98};  //Initialized array 
		
	//Statements
	printf("Begin heap sort demonstration\n\n");
	printf("Enter an unsorted array:\n");
	for (int i = 0; i < MAX_ARY_SIZE; i++)  {  //Entering an array
		printf("P%d enter the value-->", i+1);
		scanf_s("%4d", &list[i]);
	}   
	
	heapSort (list, MAX_ARY_SIZE - 1);
	printf("\nSorted array:\n");
	for (int i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", list[ i ]);
	printf("\n");
	return 0;
}     // main end

	  /*    ===================== heapSort =====================*/
void heapSort (int list[ ], int last){   
	//     Local Definitions
	int sorted;
	int holdData;

	//    Statements  
		// Create Heap
	for (int walker = 1; walker <= last; walker++)
		reheapUp (list, walker);
		// Heap created. Now sort it.
	sorted = last;
	while (sorted > 0)   {    
		holdData     = list[0];
		list[0]      = list[sorted];
		list[sorted] = holdData;
		sorted--;    
		reheapDown (list, 0, sorted);
	} // End while
	return;
}     
// End heapSort

/*    ==================== reheapUp ==================== */
void reheapUp (int heap[], int newNode){
     // Local Declarations
     int parent;
     int hold;
     // if not at root of heap
     if (newNode)   {      
	parent = (newNode - 1)/ 2;    
	if ( heap[newNode] > heap[parent] )	{   // Check child is greater than parent        
		hold = heap[parent];
		heap[parent]  = heap[newNode];
		heap[newNode] = hold;
		reheapUp (heap, parent);
	} // End if heap[]   
     } // End if newNode
return;
}     
// End reheapUp

/*    ==================== reheapDown ==================== */
void reheapDown (int heap[], int root, int last){
	// Local Declarations
	int hold;
	int leftKey;
	int rightKey;
	int largeChildKey;
	int largeChildIndex;
	
	// Statements
	if ((root * 2 + 1) <= last){   // There is at least one child       
		leftKey   = heap[root * 2 + 1];    
		if ((root * 2 + 2) <= last)       
		rightKey  = heap[root * 2 + 2];    
		else       rightKey  = -1;// Determine which child is larger    
		if (leftKey > rightKey) {        
		largeChildKey   = leftKey;
		largeChildIndex = root * 2 + 1;       
		} // End if leftKey    
	else {        
		largeChildKey   = rightKey;
		largeChildIndex = root * 2 + 2;
		} // End else    
	  // End Test if root > larger subtree    
	if (heap[root] < heap[largeChildIndex]){         // Check parent < children         
		hold = heap[root];         
		heap[root] = heap[largeChildIndex];         
		heap[largeChildIndex] = hold;         
		reheapDown (heap, largeChildIndex, last);        
		} // End if root <
	} // End if root
	return;
} // End reheapDown
