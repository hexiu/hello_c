#include<stdio.h>

#define MAX 100;

typedef struct
{
    char *ch;
    int len;
}HString;

void gets(HString *p)
{
    char ch;
    int i=0;
    p->len=MAX;
    ch=getchar();
    getchar();

    while(ch!='\n')
    {
        p->ch[i]=ch;
        printf("%c  *    ",p->ch[i]);
        ch=getchar();
        getchar();
        i++;
    }

}

//char * puts(char *p)
{

}


int main()
{
    HString h;
    gets(&h);
//    puts(&h);

}
