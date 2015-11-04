
/*  需要自己 typedef 定义的类型:
 *  ElenType(list)
 *
 *  datatype(tree)
 *
*/

#define MAXSIZE 100

/*链式结构声明*/
//====================================================

/*单链表的定义*/
typedef struct node
{
    ElemType data;
    struct  node *next;
}LNode,*LinkList;


/*双向链表的定义*/
typedef struct dlnode
{
    ElemType data;
    struct dlnode *prior,*next;
}DLNode;*DLinkList;

/*静态链表的定义*/
//#define MAXSIZE 100
typedef struct
{
    ElemType data;
    int next;
}SNode;             //结点类型
SNode sd[MAXSIZE];
int SL;             //头指针变量


/*栈的顺序存储*/
//#define MAXSIZE 100
typedef struct
{
     datatype data[MAXSIZE];
     int top;
}SeqStack;

/*栈的链式存储*/
typedef struct stacknode
{
     Elemtype data;
     struct stacknode *next;
}slStacktype;

/*队列的定义*/
//#define MAXSIZE 100
typedef struct
{
    datatype data[MAXSIZE];
    int rear,front;
}SeQueue;

/*循环队列的定义*/
typedef struct
{
    datatype data[MAXSIZE];
    int front,rear;
}CSeQueue;

/*链队列*/
typedef struct node
{
    datatype data;
    struct node *next;
}QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
}LQueue;



/*串存储的定义*/
//#define MAXSIZE 100
typedef struct
{
     char ch[MAXSIZE];
     int len;
}SString;

/*堆串存储的定义*/
typedef struct
{
    char *ch;
    int len;
}HString;

/*块链串的定义*/
#define BLOCK_SIZE 4        //每个结点存放的字符数
typedef struct block
{
     char ch[BLOCK_SIZE];
     struct block *next;
}Block;
typedef struct
{
     Block *head;           //块链串头指针
     Block *tail;           //快链串尾指针
     int len;               //字符串长度
}LString;

/*三元组数据结构类型定义*/
//#define MAXSIZE 1000
typedef struct
{
    int row,col;
    ElemType value;
}Triple;
typedef struct
{
     Triple data[MAXSIZE];
     int rows,cols,nums;
}TSMatrix;

/*十字链表的数据结构类型定义*/
typedef struct OLNode
{
     int row,col;
     ElemType value;
     struct OLNode *right,*down;
}OLNode,*OLink;
typedef struct
{
     OLink *rowhead,*colhead;
     int rows,cols,nums;
}*CrossList;

/*广义表的存储*/

/*头尾链表的存储结构*/
typedef struct GLNode
{
     int tag;
     union
     {
        AtomType atom;
        struct
        {
            struct GLNode *head,*tail;
        }LNode;
     }atom_LNode;
}GLNode,*GList;

/*线性链表的存储结构*/
typedef struct GLNode
{
     int tag;
     union
     {
          AtomType atom;
          struct GLNode *head;
     }atom_LNode;
     struct GLNode *tail;
}GLNode,*GList;


/*树型结构的声明*/
//==============================================================

/*树的顺序存储*/

#define MAX 100
typedef struct
{
    datatype SqBiTree[MAX+1];
    int nodemax;
}Bitree;


/*树的链式存储*/
typedef struct Node
{
    datatype data;
    struct Node *lchild
    struct Node *rchild
}BiTNode,* BiTree;





