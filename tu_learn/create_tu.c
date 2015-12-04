#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 20
#define INFINITY 32768

typedef char vextype;

typedef struct
{
    int arcs[MAXVEX][MAXVEX];
    vextype vex[MAXVEX];
    int vexnum;
    int arcnum;
}adjmatrix;

typedef adjmatrix Graph;

/* 邻接算法*/

void create(adjmatrix *G)
{
    int i,j,k,weight,vex1,vex2;
    printf("请输入无向图中的顶点数和边数:\n");
    scanf("%d,%d",&G->vexnum,&G->arcnum);
    getchar();
    for(i=1;i<=G->vexnum;i++)
        for(j=1;j<=G->vexnum;j++)
        {
             G->arcs[i][j]=INFINITY;
        }


    {
            int i,j;
            for(i=1;i<=G->vexnum;i++){
                for(j=1;j<=G->vexnum;j++){
                    printf("%d  ",G->arcs[i][j]);
                }
                printf("\n");
            }


     }
    printf("请输入无向图中%d个顶点：\n",G->vexnum);
    for(i=1;i<=G->vexnum;i++)
    {
         printf("No.%d个结点：顶点V",i);
         scanf("%c",&G->vex[i]);
         getchar();
    }
    printf("请输入无向网中的%d条边:\n",G->arcnum);
    for(k=0;k<G->arcnum;k++)
    {
         printf("\nNo.%d条边：    顶点V\n",k+1);
         scanf("%d",&vex1);
         getchar();
         printf("---顶点");
         scanf("%d",&vex2);
         getchar();
         printf("权值：");
         scanf("%d",&weight);
         getchar();
         G->arcs[vex1][vex2]=weight;
         G->arcs[vex2][vex1]=INFINITY;
    }

            {
            int i,j;
            for(i=1;i<=G->vexnum;i++){
                for(j=1;j<=G->vexnum;j++){
                    printf("%d  ",G->arcs[i][j]);
                }
                printf("\n");
            }


         }

}


//global values
int visited[MAXVEX]={0};

int FirstAdjvex(Graph g,int v)
{
    printf("Enter FirstAdjvex!  v == %d g.vex　%c \n",v,g.vex[v]);
    int i;
    for(i=1;i<=g.vexnum;i++)
    {
        printf("will Go banck .arcs[%d]= %d \n ",i,g.arcs[v][i]);
         if(g.arcs[v][i]!=INFINITY)
            return i;
    }
    printf("go back  v  %d\n",v);
    return v;
}

int NextAdjvex(Graph g,int v0,int w)
{
    printf("Enter NextAdjvex... !\n");
     int i;
     for(i=w+1;i<=g.vexnum;i++)
     {
        printf("Will go back from NextAdjvex\n");
 //       if(visited[i]!=1&&g.vex[i]!=g.vex[v0]&&g.vex[i]!=g.vex[w])
        if(g.arcs[v0][i]!=INFINITY)
            return i;
     }
     return -1;
}

void DFS(Graph g,int v0)
{
    printf("This is DFS. v0 = %d  \n",v0);
    int w;
//    visit(v0);
    printf("\n -->  The  Point: %c\n\n\n",g.vex[v0]);

    visited[v0]=1;
    w=FirstAdjvex(g,v0);
    printf("Go back from FirstAdjvex. w =%d \n",w);
    while(w!=-1)
    {
        getchar();
        getchar();
         if(!visited[w]) DFS(g,w);
         printf("Will go NextAdjvex ... \n");
         w=NextAdjvex(g,v0,w);
         printf("Go back from NextAdjvex. w =%d \n",w);

    }
}

void TraverseG(Graph g)
{
    int v;
    printf("**%d\n",g.vexnum);
    for(v=1;v<=g.vexnum;v++)
    {
        visited[v]=0;
        printf("TraverseG for 1 ok!\n");
    }
    for(v=1;v<=g.vexnum;v++)
    {
        if(!visited[v]){
            printf("Enter DFS\n");
            DFS(g,v);
            printf("Go back.\n");

        }

    }
}


/****************************************************************
 *
 *Guangdu Youxian
 *
 * *************************************************************/
/*
void BFS(Graph g,int v0)
{
     printf("  -->#   The Point %c \n",g.vex[v0]);
     visited[v0]=1;
     InitQueue(&Q);
     EnterQueue(&Q,v0);
     while(!Empty(Q))
     {
        DeleteQueue(&Q,&v);
        w=FirstAdj(g,v);
        while(w!=-1){
            if(!visited[w])
                printf("-->#   The Point %c \n",g->vex[w]);

        }
     }
}

*/



int main()
{
    adjmatrix G;
    create(&G);
    printf("%c %c %c",G.vex[3],G.vex[1],G.vex[2]);
    TraverseG(G);

}
