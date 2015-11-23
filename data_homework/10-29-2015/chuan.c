#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node
{
    char *ch;
    int len;
}HString;

initstring(HString *s)
{
    s->ch=NULL;
    s->len=MAX;
}


int main()
{
    HString *s;
    s=(HString *)malloc(sizeof(HString));
    s->len=100;
    initstring(s);
    printf("%d  ",s->len);


}


