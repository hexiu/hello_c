#include<stdio.h>
#include<stdlib.h>
#include"include/zhan.h"

typedef char ElemType;
typedef struct stacknode
{
    ElemType data;
    struct stacknode *next;
}slStacktype;


int pushLstack(slStacktype *top,ElemType x);
ElemType popLstack(slStacktype *top);

int pushLstack(slStacktype *top,ElemType x)
{
    slStacktype *p;
    if((p=(slStacktype *)malloc(sizeof(slStacktype)))==NULL) return 0;
    p->data=x;
    p->next=top->next;
    top->next=p;
    return 1;
}

Elemtype popLstack(slStacktype *top)
{
     slStacktype *p;
     Elemtype x;
     if(top->next==NULL) return NULL;
     p=top->next;
     top->next=p->next;
     x=p->date;
     free(p);
     return x;
}

int main()
{
    slStacktype top;
    ElemType ch='1';
    while(1)
    {
        printf("Enter data:");
        ch=getchar();
        getchar();
        if(ch=='0')
            break;
        else
            pushLstack(top,ch);
    }
    while(s->top!=s->buttom)
    {
        ch=popstack(slStacktype *top);

    }

}
