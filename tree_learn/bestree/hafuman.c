#include<stdio.h>
#include<stdlib.h>

#define M 100

typedef struct Htnode
{
    int weight;
    int parent,lchild,rchild;
}Htnode,Hfmtree[M+1];


int enter_data(int *p)
{
    int i,n=0;
    for(i=0;p[i-1]!=9999&&i<M;i++)
    {
        scanf("%d",&p[i]);
        n++;
    }
    printf("----------%d\n",i);
    return i-1;
}


int select_weight(Hfmtree ht,int i,int *s1,int *s2)
{
    int j,min,min1;

    for(j=1;j<=i;j++)
        if(ht[j].parent==0)
        {
            min=j;
            break;
        }
    for(;j<=i;j++)
        if(ht[j].parent==0)
        {
            min=j;
            break;
        }
    for(j=1;j<=i;j++)
    {
        if(ht[j].parent!=0) continue;
        if(ht[j].weight<ht[min].weight)
        {
            min=j;
            printf("@@@@@%d \n",min);
        //    ht[j].weight=-1;
        }
    }
    *s1=min;

    for(j=1;j<=i;j++)
    {
        if(ht[j].parent!=0) continue;
        if(ht[j].weight==ht[min].weight) continue;
    //    if(ht[j].weight==ht[min1].weight) j=j+1;
        if(ht[j].weight<=ht[min1].weight)
        {
            if(j!=min)
                min1=j;
        //        ht[j].weight=-1;
        }
    }
    *s2=min1;
    printf("########min#%d   #min1%d\n",min,min1);
}


void Print_data(int *a,Hfmtree ht,int m)
{
    int i;
    for(i=0;a[i]!=9999;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(i=1;i<=m;i++)
        printf("-- %d -- %d -- %d -- %d --\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);

}


int Create_tree(Hfmtree ht,int *w,int n)
{
    int m,i,s1,s2;
    m=2*n-1;
    for(i=1;i<=n;i++)
//        ht[i]={w[i-1],0,0,0};
    {
        ht[i].weight=w[i-1];
        printf("%d-----%d\n",w[i-1],m);
        ht[i].parent=0;
        ht[i].lchild=0;
        ht[i].rchild=0;
    }
    for(i=n+1;i<=m;i++)
//   ht[i]={0,0,0,0};
    {
        ht[i].weight=0;
        ht[i].parent=0;
        ht[i].lchild=0;
        ht[i].rchild=0;
    }

    Print_data(w,ht,m);


     for(i=n+1;i<=m;i++)
    {
         select_weight(ht,i-1,&s1,&s2);
         printf("s1   s2     *s1   *s2!!!!!!%d %d %d %d\n",s1,s2,ht[s1].weight,ht[s2].weight);
         ht[i].weight=ht[s1].weight+ht[s2].weight;
         ht[i].lchild=s1;
         ht[i].rchild=s2;
         ht[s1].parent=i;
         ht[s2].parent=i;
         printf("%d==========\n",i);
    Print_data(w,ht,m);
    }

}





int main()
{
    int a[M];
    int i,n,m;
    Hfmtree ht;
    n=enter_data(a);
    m=2*n-1;
    Create_tree(ht,a,n);
    Print_data(a,ht,m);
}

