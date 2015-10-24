#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	struct node *next;
} LNode,*LinkList;

int main()
{
	int test;	
	LinkList f=NULL,new,n;

	while(1)
	{
		new=(LinkList)malloc(sizeof(LNode));
		printf("Enter a number:");
		scanf("%d",&test);
		if(test==-1) break;
		new->num=test;
		printf("%d\n",new->num);
		if(f==NULL)	
		{
			f=new;
			f->next=NULL;
			n=new;
		}	
		else
		{
			n->next=new;
			new->next=NULL;
			n=new;	
		}	

	}

	for(n=f;n!=NULL;n=n->next)
		printf("-- %d ---\n",n->num);
}
