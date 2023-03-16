#include <stdio.h>
int Stack[10];
int cur;
 
char Grapic[3][3] = {{'1','2','3'}, {'-','-','-'}, {'-','-','-'}};
void GrapichArray()
{
 for(int i = 0; i < 3; i++)
 {
  for(int j = 0; j < 3; j++)
  {
   printf("%c  ", Grapic[j][i]);
  }
  printf("\n");
 }
 printf("\n");
}


//***** Stack 이용을 위한 함수 *****//
void InitStack()
{
    cur = -1;
}
 
void Push(int data)
{
    if (cur >= 10 - 1)
    {
        //printf("Stack overflow!!!\n");
        return;
    }
 
    Stack[++cur] = data;
}
 
int Pop()
{
    if (cur < 0)
    {
        //printf("Stack is already empty!!!\n");
        return 0;
    }
 
    return Stack[cur--];
}
 
int IsEmpty()
{
    if (cur < 0)
        return 1;
    else
        return 0;
}
///////////////////////////////////////
 
void Print(int n, int from, int to)
{
    printf("원반%d를 %d에서 %d로 이동\n", n, from, to);

 int nIndexFrom = -1;
 for(int i= 0; i < 3; i++)
 {
  if(Grapic[from - 1][i] == 48 + n)
   nIndexFrom = i;
 }

 int nIndexToEmpty = -1;
 for(int i= 2; i >= 0; i--)
 {
  if(Grapic[to - 1][i] == '-')
  {
   nIndexToEmpty = i;
   break;
  }
 }
 
 Grapic[to - 1][nIndexToEmpty] = Grapic[from - 1][nIndexFrom];
 Grapic[from - 1][nIndexFrom] = '-';

 GrapichArray();

 printf("\n");

}
 
// 하노이 타워 반복문 구현 함수(스택 이용)
void Hanoi(int n, int from, int by, int to)
{
    int bContinue = 1;
    InitStack();
 
    while (bContinue)
    {
        while (n > 1)
        {
            Push(to);
            Push(by);
            Push(from);
            Push(n);
            --n;
            Push(to);
            to = by;
            by = Pop();
        }
        Print(n, from, to);
        if (!IsEmpty())
        {
            n = Pop();
            from = Pop();
            by = Pop();
            to = Pop();
            Print(n, from, to);
            --n;
            Push(from);
            from = by;
            by = Pop();
        }
        else
            bContinue = 0;
    }
}
int main(int arc, char** argv)

{
  
 printf("하노이 타워 반복문 구현\n");

 GrapichArray();

 Hanoi(3, 1, 2, 3);

    return 0;
}