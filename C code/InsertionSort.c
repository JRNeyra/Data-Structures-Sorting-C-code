/************************************************************************ 
Description: Program to sort an array of integers in ascening order 
using the insertion technique
Author: Jose Neyra
InsertionSort.cpp : Defines the entry point for the console application.
*************************************************************************/

#include "stdafx.h"
#include <stdio.h>
#define MAX_ARY_SIZE 10

/* Prototype Declarations */
void  insertionSort (int list[ ], int last );

int main ( void ){
	/* Local Declarations */
	int ary[ MAX_ARY_SIZE ]; 
	
	/*    Statements */
	printf( "Unsorted array: \n");
	for (int i = 0; i < MAX_ARY_SIZE; i++ ){     
		printf( "pl enter the value--> ");
		scanf_s("%d", &ary[ i ] ); 
	}
	
	insertionSort ( ary, MAX_ARY_SIZE - 1);  // Calling of function
	printf( "\nSorted array:   " );
	for (int i = 0; i < MAX_ARY_SIZE; i++)
		printf( "%3d", ary[ i ] );
	printf( "\n" );
	return 0;
} /* Main Ends*/

/*==================== insertionSort =====================*/
void insertionSort (int list[], int last){
	// Local Definitions
	int hold = 0;
	int walker = 0;
	
	// Statements
	for (int current = 1; current <= last; current++)   {    
		hold = list[current];    
		for (walker = current - 1; walker >= 0 && hold < list[walker]; walker--)            
			list[walker + 1] = list[walker];    
		list [walker + 1] = hold;   
	} // for current ends
	return;
}     // insertionSort
