#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int a[10];
	int top;
}Seqstack;

int main()
{
	int i;
		Seqstack *b;
		b=malloc(sizeof(Seqstack));
		b->top=-1;
		for(i=0;i<10;i++)
		{
			b->top++;
			printf("nihao:");
			scanf("%d",&b->a[b->top]);
			getchar();
		}
		for(i=-1;i<=b->top;b->top--)
		{
			if(b->top!=-1)
				printf("%d   ",b->a[b->top]);

		}
			printf("\n");
}

