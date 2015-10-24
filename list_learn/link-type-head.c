#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	struct 	node *next;	
} LNode,*LinkList;

int main()
{
	LinkList f=NULL,n,new;
	int test;
	while(1)
	{
		new=(LinkList)malloc(sizeof(LNode));
		
		if(f==NULL)
		{
			f=new;
			f->next=NULL;
			continue;
		} 
		printf("Enter a number:");
		scanf("%d",&test);
		if(test==-1)	
			break;
		new->num=test;	
		printf("%d\n",new->num);
		if(f->next==NULL)
		{
			f->next=new;
			new->next=NULL;	
		}	
		else
		{
			
			new->next=f->next;
			f->next=new;	
		}		
		
	}

	for(n=f->next;n!=NULL;n=n->next)
		printf("--%d--\n",n->num);
}
