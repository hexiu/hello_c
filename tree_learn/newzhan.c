#include<stdio.h>
#include<stdlib.h>

typedef char datatype;

typedef struct node
{
    datatype data;
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

int pushstack(datatype a)
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

datatype popstack()
{
    PNode p;
    datatype x;
    if(s->top!=s->buttom)
    {
        p=s->top;
        x=p->data;
        s->top=s->top->next;
        free(p);
    }
    return x;
}



int main()
{
    datatype x=1;
    PNode n;
    init_stack();
    while(1)
    {
        printf("Enter data:");
        scanf("%c",&x);
        if(x=='0') break;
        getchar();
        pushstack(x);

    }
    printf("%d \n",s->top->data);
    while(s->top!=s->buttom)
    {
        x=popstack();
         printf("%c ",x);
    }
}
