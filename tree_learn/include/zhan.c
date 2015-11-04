#include"zhan.h"


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


