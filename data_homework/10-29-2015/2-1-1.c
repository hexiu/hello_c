#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct Stringinit{
    char str[MAX];
    int length;
} String,*String1;

String1 init_string()
{
    String x;
    String1 y;
    x.length=MAX;
    y=&x;
    return y;
}

String1 replace(String1 y)
{
    char ch1,ch2;
    char * ch=y->str;
    int i;
     printf("Please enter ch1:");
     ch1=getchar();
     getchar();
     printf("Please enter ch2:");
     ch2=getchar();
     getchar();
     for(i=0;*ch!='\0';i++)
     {
         printf("%c",*ch);
         if( *ch== ch1 )
            *ch=ch2;
         *ch++;
     }
     return y;
}

void puts1(char * x)
{
    char *q=x;
    while(*q != '\0')
    {
        printf("%c ",*q);
        *q++;
    }

}

char * gets1(char * x)
{
    char ch;
    char *q=x;
    int i=0;
    ch=getchar();
    getchar();
    printf("*****\n");
    while(ch!='\n')
    {
        printf("%c  ",ch);
         *x=ch;
         printf("%c   ",*x);
         *x++;
         i++;
         ch=getchar();
    }

    if( i < MAX)
        *x='\0';
    printf("%s %d\n*********",q,i);
    puts1(q);
    return q;
}

int main()
{
    String1 x,z;
    x=init_string();
    printf("Enter String:");
    gets1(x->str);
    printf("%s\n",x->str);
    printf("############");
    z=replace(x);
    printf("%s\n",z->str);
}







