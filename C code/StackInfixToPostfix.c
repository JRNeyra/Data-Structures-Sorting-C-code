/**************************************************************************************
Description: This is an example of C code to convert an INFIX expression to a POSTFIX
expression using a Stack data structure.
Author: Jose Neyra
***************************************************************************************/


// NeyraJ_StackInFixToPostfix.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include<stdio.h>
#include<stdbool.h>              //For isOperator(char) Line40
#include<stdlib.h>               //For exit(), gets and puts
#include<ctype.h>                //For isdigit(char) and isalpha(char) Line75
#pragma warning(disable : 4996)  //For strcat(infix, char) Line67 
#define SIZE 20

//Global Variables:
char stack[SIZE];       //Initialized stack array
int top = -1;           //Initialized stack counter

//Stack Functions:
void push(char data) {
	if (top >= SIZE - 1) {
		printf("\nStack Overflow.");
	}
	else {
		top = top + 1;
		stack[top] = data;
	}
}
char pop() {
	char data;
	if (top <0)	{
		printf_s("\nStack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else {
		data = stack[top];
		top = top - 1;
		return(data);
	}
}
//End of Stack Functions

//Check Functions
bool isOperator(char symbol) {
	if (symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
		return true;
	}
	else {
		return false;
	}
}
int precedenceLevel(char symbol) {
	if (symbol == '^' || symbol == '%') {
		return(3);
	}
	if (symbol == '*' || symbol == '/') {
		return(2);
	}
	else if (symbol == '+' || symbol == '-') {         
		return(1);
	}
	else {
		return(0);
	}
}
//End Check Functions

//Conversion Function
void InToPost(char infix[], char postfix[]) {
	int i=0, p=0;
	char data, x;
	
	push('(');                               
	strcat(infix, ")");      //Add ')' to infix expression 
		
	data = infix[i];         //Initialized for While Loop

	while (data != '\0') {       //Run loop until end of infix expression
		if (data == '(') {
			push(data);
		}
		else if (isdigit(data) || isalpha(data)) {
			postfix[p] = data;              //Add operand symbol to postfix expression
			p++;
		}
		else if (isOperator(data)) {        //Check for operator
			x = pop();
			while (precedenceLevel(x) >= precedenceLevel(data) && isOperator(x)) {
				postfix[p] = x;             //Pop all higher precendence operator
				p++;
				x = pop();                  //Add them to postfix expresion
			}
			push(x);
			
			push(data);                //Push current oprerator symbol to stack
		}
		else if (data == ')') {        //Check for ')' 
			x = pop();                 
			while (x != '(') {         // Continue to pop until '('  
				postfix[p] = x;
				p++;
				x = pop();
			}
		}
		else {                         //Check for invalid expression
			printf_s("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}
		i++;
		data = infix[i];               //Go to next symbol of infix expression
	} 

	if (top>0) {
		printf_s("\nInvalid infix Expression.\n");        
		getchar();
		exit(1);
	}
	
	postfix[p] = '\0';                  //End of postfix stack                            
}
//End Conversion Function

int main()
{
	char infix[SIZE], postfix[SIZE];    //Initialized arrays SIZE 20

	printf_s("Please enter an Infix expression of up to 20 characters: ( + - * / () ^ ");
	printf_s("%s", "%");
	printf_s(" symbols are allowed)\n");
	gets(infix);

	InToPost(infix, postfix);                   
	printf("Postfix Expression: ");
	puts(postfix);                     

	return 0;
}
