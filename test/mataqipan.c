#include<stdio.h>

#include<stdlib.h>

 

#define STACK_INIT_SIZE 100

#define STACKINCREMENT 10

 

typedef struct //记录坐标位置

{

	    int x;

		    int y;

}PosType;

typedef struct //骑士跳步

{

	    PosType seat; 

		    int di; //标记探索的下一个方向

}SElemType;

typedef struct//栈的结构体

{   

	    SElemType base;

		    SElemType top;

			    int stacksize;

}SqStack;   

 

int Init1[8][8] = { {0} };//此棋盘用以记录所走过的路

int Init2[8][8] = {  

	    {2,3,4,4,4,4,3,2},//初始化棋盘，并标记每个位置所能跳的方向

		    {3,4,6,6,6,6,4,3},//例如当为2时，表示下一步只有两个方向可跳

			    {4,6,8,8,8,8,6,4},//此棋盘用以记录跳棋步骤

				    {4,6,8,8,8,8,6,4},

					    {4,6,8,8,8,8,6,4},

						    {4,6,8,8,8,8,6,4},

							    {3,4,6,6,6,6,4,3},

								    {2,3,4,4,4,4,3,2},};

int HTry1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};//跳马的下一步的x位置

int HTry2[8] = {1, 2, 2, 1, -1, -2, -2, -1};//跳马的下一步的y位置

 

void MarkPrint(PosType pos);//此路不能通过，仍标记为0

PosType NextPos(PosType curpos,int x);//按顺时针寻找下一个方向

void FootPrint(PosType &curpos,int surstep);//此路能过标记相应的步数

int Pass(PosType &curpos);//判断此路是否能通过

int InitStack(SqStack &S);//初始化栈

void DestroyStack(SqStack &S);//销毁栈

int StackEmpty(SqStack &S);//判断栈是否为空

int Push(SqStack &S,SElemType e);//入栈

int Pop(SqStack &S,SElemType &e);//出栈

void print(int curstep);//打印路线

 

int main()

{

	    SqStack S;

		    SElemType e;

			    PosType Mincurpos,curpos,start;

				    int curstep;

					     

					    InitStack(S);

						    printf(请输入起始位置);

							    scanf(%d%d,&start.x,&start.y);

								    curpos = start;

									    curstep = 1;

										    do{

												        if(Pass(curpos)) {

															            FootPrint(curpos,curstep);

																		            e.di = 0;

																					            e.seat= curpos;

																								            Push(S,e);

																											            if(curstep == 64) {

																															                print(curstep);

																																			                DestroyStack(S);

																																							                return 1;

																																											            }

																														            curpos = NextPos(curpos,e.di);

																																	            curstep ++;

																																				        }

														        else {

																	            if(!StackEmpty(S)) {

																					                Pop(S,e);

																									                curstep --;

																													                while(e.di == 7 && !StackEmpty(S)) {

																																		                    MarkPrint(e.seat); 

																																							                    Pop(S,e);

																																												                    curstep --; 

																																																	                }

																																	                if(e.di  7) {

																																						                    Mincurpos = curpos;

																																											                    e.di ++;

																																																                    curpos = NextPos(e.seat,e.di);

																																																					                    while(Mincurpos.x == curpos.x && Mincurpos.y == curpos.y && e.di  7) {

																																																											                        e.di ++;//判断此位置的下一个位置的八个方向的最小值是否相同，若相同则直接跳过

																																																																	                        curpos = NextPos(e.seat,e.di);

																																																																							                    }

																																																										                    Push(S,e);

																																																															                    curstep ++;

																																																																				 

																																																																				                }

																																					            }

																				        }

																    }while(!StackEmpty(S));

											    DestroyStack(S);

											    return 0;

}

  

void print(int curstep)

{

	    for(int i = 0; i  8; i++)  {

			            for(int j = 0; j  8; j++) 

						                  printf(%3d,Init1[i][j]);

						            printf(n);

									        }

		    printf(n);printf(n);

			    getchar();

}

 

void MarkPrint(PosType pos)

{

	    Init1[pos.x][pos.y] = 0;

}

 

PosType NextPos(PosType curpos,int x)

{ //寻找下一个位置Init2[8][8]中最小的位置，并且此路没有走过

	    PosType MinCurpos,temp;

		 

		    MinCurpos.x = -1;

			    MinCurpos.y = -1;//置此为最小的方向

				    for(;x  8; x++) {

						        temp.x = curpos.x + HTry1[x];

								        temp.y = curpos.y + HTry2[x];

										        if(temp.x  0  temp.x  7  temp.y  0  temp.y  7  Init1[temp.x][temp.y]) continue;//保证此位置在棋盘中

												        if(MinCurpos.x == -1 && MinCurpos.y == -1)//先找到下个位置第一个合法的位置 

														              MinCurpos = temp;

														        else if( Init2[MinCurpos.x][MinCurpos.y]  Init2[ temp.x][temp.y] )//比较找最小

																              MinCurpos= temp;

																    }

					    if(MinCurpos.x == -1 && MinCurpos.y == -1)//如果没有下个位置，返回原来位置

						              return curpos;

						    return MinCurpos;

}

 

void FootPrint(PosType &curpos,int curstep) 

{

	    Init1[curpos.x][curpos.y] = curstep;

}

 

int Pass(PosType &curpos)

{

	    if(!Init1[curpos.x][curpos.y])

		          return 1;

		    else return 0;

}

 

void DestroyStack(SqStack &S)

{

	    S.base = S.top;

		    S.stacksize = 0;

}

 

int StackEmpty(SqStack &S)

{

	    if(S.base == S.top)

		          return 1;

		    else return 0;

}

 

int InitStack(SqStack &S)

{

	    S.base = (SElemType)malloc(STACK_INIT_SIZE  sizeof(SElemType));

		    if(!S.base) return 0;

			    S.top = S.base;

				    S.stacksize = STACK_INIT_SIZE;

					    return 1;

}

 

int Push(SqStack &S,SElemType e)

{

	    if(S.top - S.base = S.stacksize ) {

			        S.base = (SElemType)realloc(S.base,(STACK_INIT_SIZE+STACKINCREMENT )sizeof(SElemType));

					        if(!S.base) return 0;

							        S.top = S.base +S.stacksize;

									        S.stacksize += STACKINCREMENT;

											    }

		    S.top++ = e;

			    return 1;

}

 

int Pop(SqStack &S,SElemType &e)

{

	    if(S.top == S.base) return 0;

		    e = --S.top;

			    return 1;



}




