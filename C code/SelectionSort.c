/*************************************************************************
Description: Program to sort 10 intergers in ascending order using 
Selection Sort algorithm
Author: Jose Neyra
SelectionSort.cpp : Defines the entry point for the console application.
*************************************************************************/

#include "stdafx.h"
#include <stdio.h>

// Constants
const int cMax_Ary_Size = 10;						// Sets the max elements to 10

/* Prototype Declarations */
void selectionSort  (int list[ ], int last);

// Main
int main ( void ){
	
	/* Local Declarations */
	int   ary[10];									// Declares a 10 element array
	
	/* Statements */
	printf( "Unsorted array:\n ");
	for (int i = 0; i < cMax_Ary_Size; i++ ){		// User enters the array elements one by one.
		printf("Enter the value of element %d value-->", i);
		scanf_s("%d/n", &ary[ i ]);
	}
	
	selectionSort ( ary, cMax_Ary_Size - 1);		// Selection sort function is called and passes the array and the number 9
	
	printf( "\nSorted array:   " );
	for (int i = 0; i < cMax_Ary_Size; i++)
		printf( "%3d", ary[ i ] );printf( "\n" );
	return 0;
} /* Main Ends*/

/*=================== selectionSort ====================
Sorts list[1Élast] by selecting smallest element in unsorted portion of 
array and exchanging it withelement at beginning of the unsorted list. */
void selectionSort  (int list[ ], int last){
	
	// Local Declarations
	int smallest;
	int holdData;
	
	// Statements
	for (int current = 0; current < last; current++) {			 //First pass: current=0, last=9, smallest=0
		smallest = current;
		for (int walker = current + 1; walker <= last; walker++) //First pass: walker=1, last=9,
			if (list[ walker ] < list[ smallest ])				 
				smallest = walker;
		// Smallest selected: exchange with current     
		holdData        = list[ current ];     
		list[current]   = list[ smallest ];     
		list[smallest]  = holdData;    
	} // for current ends
	return;
} // selectionSort ends
