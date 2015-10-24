#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int id;
	int passwd;
	struct node * next;
} LNode,*Seqlist;

int id_num=0;

Seqlist newlist()
{
	Seqlist r,n,q,h=NULL;
	int i=0;	
	while(1)
	{
		n=(Seqlist)malloc(sizeof(LNode));
		if(h==NULL)
		{
			n->next=NULL;
			h=n;
			continue;
		}
		id_num++;
		n->id=id_num;
		printf("Enter %d `s passwd:",n->id);
		scanf("%d",&n->passwd);
		getchar();
		if(n->passwd==0)
		{
			free(n);
			id_num--;
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
		r->next=h->next;	
		for(n=h->next;n!=h&&i<id_num;n=n->next,i++)	
			printf(" %d     %d \n",n->id,n->passwd);
		printf("%d\n",id_num);
		return h;
}



int main()
{
	Seqlist h,p,q;
	int i,j;
	int passwd;
	h=newlist();
	printf("please enter password:");
	scanf("%d",&passwd);
	getchar();
	p=h;
	
	while(id_num--)
	{
//		printf("id_num==%d\npasswd   %d\n \n",id_num,passwd);
//		printf("*******\n");
		passwd--;
		while(passwd--)
		{
//			printf("%d\n",p->next->passwd);
			p=p->next;
		}
		q=p->next;
		passwd=p->next->passwd;
		printf("\nDel id %d,passwd is %d \n",p->next->id,p->next->passwd);
		p->next=p->next->next;
		free(q);
	
		
	}
//	printf("\nResult id is %d,passwd is %d\n",p->next->id,p->next->passwd);
	
}








