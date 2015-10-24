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
	
	Seqlist p,q=h,t,f;
	for(r=h;r->next!=NULL;r=r->next,q=r)
	{
		for(n=r,p=n->next;p->next!=NULL;p=p->next)
		{
			printf("***************\n");
			if(n->next->num>p->next->num)
			{
				if(n->next->next==p->next)
				{
					
					printf("%d %d\n",n->next->num,p->next->num);
					
					t=n->next;
					f=p->next;
					n->next=f;
					t->next=f->next;
					f->next=t;
				//	p=p->next;
					printf("%d %d\n",n->next->num,p->next->num);
					getchar();
					getchar();
					getchar();
					getchar();
				}
				else
				{
					printf("%d %d ]\n",n->next->num,p->next->num);
					t=n->next;
					n->next=p->next;
					f=p->next->next;
					n->next->next=t->next;
					p->next=t;
					t->next=f;
					printf("%d %d ]\n",n->next->num,p->next->num);

					getchar();
					getchar();
					getchar();
					getchar();
				}
			}
		}
	}	


		for(n=h->next;n!=NULL;n=n->next)
		{	
			printf("%d ",n->num);
			printf("===");
		}
		printf("\n");	
}
