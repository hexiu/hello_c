#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int num;
	struct node * next;
} LNode,*Seqlist;


Seqlist h1,h2;


Seqlist create_jihe()
{
	Seqlist n,r,h=NULL;
	while(1)
	{
//		printf("*************\n");
		n=(Seqlist)malloc(sizeof(LNode));
		if(h==NULL) 
		{
			h=n;
			h->next=NULL;
			continue;
		}
//		printf("*************\n");
		printf("Please enter a number:");
		scanf("%d",&n->num);
		getchar();
		if(n->num==1234)
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
	  printf("%d  \n",n->num);
		
	return h;
}

Seqlist add()
{
	Seqlist m,q,p;
	
	for(p=h1;p->next!=NULL;)
	{
			printf("%d h1\n",p->next->num);
		for(q=h2;q->next!=NULL;q=q->next)	
		{
			printf("%d h2\n",q->next->num);
			if(p->next->num!=q->next->num)
			{
				continue;
			}
			else
			{
				break;
			}
		
		}
		if(q->next==NULL)
		{
			m=p->next;
			p->next=p->next->next;
			m->next=NULL;
			q->next=m;
			
		}
		else
		{
			m=p->next;
			p->next=p->next->next;
			free(m);
		}
	}
	return h2;
}


Seqlist minus()
{
	Seqlist m,p,q;
	
	for(p=h1;p->next!=NULL;)
	{
			printf("%d h1\n",p->next->num);
		for(q=h2;q->next!=NULL;q=q->next)	
		{
			printf("%d h2\n",q->next->num);
			if(p->next->num!=q->next->num)
			{
				continue;
			}
			else
			{
				break;
			}
		
		}
		if(q->next==NULL)
		{
			p=p->next;
			
		}
		else
		{
			m=p->next;
			p->next=p->next->next;
			free(m);
		}
	}
	return h1;
}


Seqlist time()
{
	Seqlist m,p,q;	
	for(p=h1;p->next!=NULL;)
	{
			printf("%d h1\n",p->next->num);
		for(q=h2;q->next!=NULL;q=q->next)	
		{
			printf("%d h2\n",q->next->num);
			if(p->next->num!=q->next->num)
			{
				continue;
			}
			else
			{
				break;
			}
		
		}
		if(q->next!=NULL)
		{
			p=p->next;
			
		}
		else
		{
			m=p->next;
			p->next=p->next->next;
			free(m);
		}
	}
	return h1;
}




int main()
{
	Seqlist h,n;
	char cr;
	h1=create_jihe();
	h2=create_jihe();
	printf("You want (+,-,*):");
	scanf("%c",&cr);
	getchar();
	switch(cr)
	{
		case '+':	h=add();
			break;
		case '-':	h=minus();
			break;
		case '*':	h=time();
			break;
		default :  break;			
	}
	

	for(n=h->next;n!=NULL;n=n->next)
	  printf("%d ",n->num);
	printf("\n");
}




