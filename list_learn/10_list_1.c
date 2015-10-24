#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	struct node * next;
} LNode,*Seqlist;

Seqlist newlist()
{
	Seqlist r,n,q,h=NULL;
	
	while(1)
	{
		n=(Seqlist)malloc(sizeof(LNode));
		if(h==NULL)
		{
			n->next=NULL;
			h=n;
			continue;
		}
		printf("Enter a num:");
		scanf("%d",&n->num);
		if(n->num==0)
		{
			free(n);
			break;
		}
		n->next=NULL;
		if(h->next==NULL)
		{
			h->next=n;
			r=n;
		}
		else
		{
			r->next=n;
			r=n;
		}
	
	}
		for(n=h->next;n!=NULL;n=n->next)	
			printf("%d",n->num);
		printf("\n");
	return h;
}


int main()
{
	Seqlist h,p,q;
	int num,i=0;
	h=newlist();
	printf("Enter num:");
	scanf("%d",&num);
	for(p=h->next,q=p;p!=NULL;p=p->next)								
	{
		i++;
		if(i<num+1)
			continue;
		else 
			q=q->next;
	}	
	printf("\t%d\n",q->num);
}

