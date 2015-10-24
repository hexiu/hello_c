#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int num;
	struct node * next;
} LNode,*Seqlist;


int main()
{
	Seqlist r,n,h=NULL;
	char jud;
	while(1)
	{
		n=(Seqlist)malloc(sizeof(LNode));
		if(h==NULL)
		{
			h=n;
			h->next=NULL;
			continue;	
		}	
		printf("Please enter a number:");
		scanf("%d",&n->num);
		getchar();
		//printf("nihao %d",n->num);
		if(n->num==0) {  free(n);   break;}	
		if(h->next==NULL)
		{
			n->next=NULL;
			h->next=n;
			r=n;
		}
		else
		{
			n->next=NULL;
			r->next=n;
			r=n;
		}
		/*
		printf("Continue?(y|n)");
		jud=getchar();
		if(jud=='n'||jud=='N')
			break;	
		*/
	}
	
	Seqlist p,q,t1,t2,z,y;
	for(r=h;r->next!=NULL;r=r->next)
	{
		for(n=r->next;n->next!=NULL;n=n->next)
		{
			printf("***************\n");
			if(r->next->num>n->next->num)
			{
				p=r;
				q=n;
				z=p->next;
				y=q->next;
				t1=p->next->next;
				t2=q->next->next;
				p->next=y;
				p->next->next=t1;
				q->next=z;
				q->next->next=t2;
				
			 
			}


		for(n=h->next;n!=NULL;n=n->next)
		{	
			printf("%d ",n->num);
			printf("===");
		}
		printf("\n");	
			getchar();
			getchar();
		}
	}	


		for(n=h->next;n!=NULL;n=n->next)
		{	
			printf("%d ",n->num);
			printf("===");
		}
		printf("\n");	
}
