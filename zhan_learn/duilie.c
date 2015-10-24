#include<stdio.h>
#include<stdlib.h>

#define MAXNUM 10

/*
typedef struct node
{
	char a[MAXNUM];
	int top;
}Seqstack;
*/

typedef struct node1
{
	char b[MAXNUM];
	int rear,front;
}Csequeue;


Csequeue* init()
{
	q=malloc(sizeof(Csequeue))
	q->front=q->rear=MAXNUM-1;
	return q;
}

int Insequeue(Csequeue *q,datatype x)
{
	if((q->rear+1)  % MAXNUM == q->front)
	
}


