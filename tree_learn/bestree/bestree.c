#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Bitree
{
    int weight;
    struct Bitree *lchild,*rchild;
}Bitnode,*Bitree;


int * enter_data(int *p)
{
    int i;
    for(i=0;p[i-1]!=9999&&i<MAX;i++)
    {
        scanf("%d",&p[i]);
    }

}

int Create_tree(Bitree *root)
{

}


void Print_data(int *a)
{
    int i;
    for(i=0;a[i]!=9999;i++)
        printf("%d ",a[i]);
}


int main()
{
    int a[MAX];
    int i;
    Bitree root;
    enter_data(a);
    Create_tree(&root,a,);
    Print_data(a);
}

