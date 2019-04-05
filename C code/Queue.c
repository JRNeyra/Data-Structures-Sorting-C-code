/**********************************************************************
Description: C program example that describes the use of the Queue 
data structure with enqueue and dequeue functions.
Author: Jose Neyra
**********************************************************************/

//NeyraJ-Queue.cpp: Defines the entry point for the console application.


#include "stdafx.h"
#include<stdlib.h>
#include<stdio.h>

struct queueNode {
	int data;
	struct queueNode* next;
};

struct queueNode* front = NULL;
struct queueNode* rear = NULL;

void Enqueue(int x) {
	struct queueNode* temp = (struct queueNode*)malloc(sizeof(struct queueNode*));
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	struct queueNode* temp = front;
	if (front == NULL) return;
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

void Front() {
	if (front == NULL) {
		printf_s("Queue is empty\n");
	}
	else printf_s("%d", front->data);
}

void Print() {
	struct queueNode* temp = front;
	while (temp != NULL) {
		printf_s("%d ", temp->data);
		temp = temp->next;
	}
	printf_s("\n");
}


int main()
{
	Enqueue(7); Print();
	Enqueue(5); Print();
	Enqueue(3); Print();
	Front();
	Dequeue();  Print();
	Enqueue(10); Print();
	Front();
	Enqueue(2); Print();
	Dequeue();  Print();
	Enqueue(1); Print();
}
