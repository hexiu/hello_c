#include<stdio.h>
#include<stdlib.h>
#include"include/erchashu.h"

typedef BiTree elemtype;

typedef struct node
{
    elemtype data;
    struct node *next;
}Node,*PNode;

typedef struct stack
{
    struct node *top;
    struct node *buttom;
}Stack,*Pstack;

Stack sp;
Pstack s=&sp;

Pstack init_stack()
{
    s->top=(PNode)malloc(sizeof(Node));
    if(s->top==NULL)
    {
        printf("Error");
        exit(1);
    }
    s->buttom=s->top;
    s->top->next=NULL;
    return s;
}

int pushstack(elemtype a)
{
    PNode pNew=(PNode)malloc(sizeof(Node));
    if(pNew==NULL)
    {
         printf("Error\n");
         exit(1);
    }
    pNew->next=s->top;
    s->top=pNew;
    pNew->data=a;

}

elemtype popstack()
{
    PNode p;
    elemtype x;
    if(s->top!=s->buttom)
    {
        p=s->top;
        x=p->data;
        s->top=s->top->next;
        free(p);
    }
    return x;
}

elemtype topstack()
{
    PNode p;
    elemtype x;
    if(s->top!=s->buttom)
    {
         p=s->top;
         x=p->data;

    }
    return x;
}


/*树的数据结构
 *顺序结构 Bitree
 *链式结构 BitNode *BiTree
 *
 *
 *
 * */
//typedef datatype char;

//BiTree T=NULL;



int CreateBiTree(BiTree *T)
{
     char data;
     printf("Enter data:");
     scanf("%c",&data);
     getchar();
     if(data=='#')
     {
          *T=NULL;
     }
     else
     {
          *T=(BiTree)malloc(sizeof(BiTNode));
          (*T)->data=data;
          CreateBiTree(&((*T)->lchild));
          CreateBiTree(&((*T)->rchild));
     }
     return 0;
}

void Visit(BiTree T)
{
 //    if(T->data!='#')
     {
         printf("%c ",T->data);
     }
}

//先序遍历
void PreOrder(BiTree T)
{
     if(T!=NULL)
     {
         Visit(T);
         PreOrder(T->lchild);
         PreOrder(T->rchild);
     }
}

//中序遍历
void InOrder(BiTree T)
{
     if(T!=NULL)
     {
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
     }
}

//后续遍历
void PostOrder(BiTree T)
{
     if(T!=NULL)
     {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);
     }
}


//先序遍历的非递归实现:
void PreFOrder(BiTree T)
{
    BiTree p=T;
    while(p!=NULL||(s->top!=s->buttom))
    {
         if(p!=NULL)
         {
             pushstack(p);
             printf("%c ",p->data);
             p=p->lchild;

         }
         else
         {
            p=popstack();
            p=p->rchild;
         }
    }

}

//中序非递归遍历
void InFOrder(BiTree T)
{
    BiTree p=T;
    while(p!=NULL||s->top!=s->buttom)
    {
        if(p!=NULL)
        {
            pushstack(p);
            p=p->lchild;
        }
        else
        {
         //   printf("####################s");
             p=topstack();
             printf("%c ",p->data);
             p=popstack();
             p=p->rchild;
        }
    }
}



//后续非递归遍历(Have Problem)
PostFOrder(BiTree T)
{
    BiTree q=T;
    while(p!=NULL||s->top!=s->buttom)
    {
         if(p!=NULL)
         {
             pushstack(p->lchild);
             p=p->lchild;
         }
         else
         {
             p=topstack();

             p=p->rchild;
             printf("");
         }
    }
}



int main()
{

    BiTree T;
    CreateBiTree(&T);
    printf("************\n");
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    printf("\n");
    PreFOrder(T);
    printf("\n");
    InFOrder(T);
}
