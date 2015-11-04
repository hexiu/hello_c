//typedef DiTree char;

typedef char ElemType;
typedef struct stacknode
{
    ElemType data;
    struct stacknode *next;
}slStacktype;


int pushLstack(slStacktype *top,ElemType x);
ElemType popLstack(slStacktype *top);





