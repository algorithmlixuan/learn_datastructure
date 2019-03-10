#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

#define InitSize 100
#define ElemType int
#define MaxSize 50

//顺序表定义
typedef struct{
    ElemType *data;
    int length;
}SeqList;

//将e元素插入顺序表第i个位置
bool ListInsert(SeqList &L, int i, ElemType e)
{
    if(i < 1 || i > L.length + 1)
        return false;
    if(L.length >= MaxSize)
        return false;
    for(int j = L.length; j >= i ;j--)
       L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length ++;
    return true;
}

//删除顺序表L中第i位置的元素
bool ListDelete(SeqList &L, int i, ElemType &e)
{
    if(i < 1 || i > L.length)
        return false;
    e = L.data[i-1];
    for(int j = i; j < L.length; j++)
        L.data[j-1] = L.data[j];
    L.length --;
    return true;
}

//查找元素e，并返回位置
int LocateElem(SeqList &L, ElemType e)
{
    for(int i = 0; i < L.length; i++)
        if(L.data[i] == e) return i + 1;
    return 0;
}

//删除最小值
bool DEL_MIN(SeqList &L, ElemType &value)
{
    int pos = 0;
    if(L.length <= 0) return false;
    value = L.data[0];
    for(int i = 1; i < L.length; i++)
    {
        if(L.data[i] < value) 
        {
            L.data[i] = value;
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length --;
    return true;
}

//遍历顺序表
bool BianLi(SeqList &L)
{
    if(L.length <= 0) return false;
    cout << "顺序表元素为：" << endl;
    for(int i = 0; i < L.length; i++)
        cout << L.data[i] <<endl;
    return true;
}

//删除顺序表中值为x的元素
void del_x(SeqList &L, ElemType x)
{
    int k = 0;//记录不为x的元素
    for(int i = 0; i < L.length; i++)
    {
       if(L.data[i] != x)
       {
           L.data[k] = L.data[i];
           k++;
       }
       L.length = k;
    }
}

//将顺序表逆置
void Reverse(SeqList &L)
{
    ElemType temp;
    for(int i = 0; i < L.length / 2 ; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

//构造顺序表
void Build(SeqList &L)
{
    L.data = new ElemType[InitSize];
    cout << "请输入顺序表的长度" << endl;
    cin >> L.length;
    cout << "请输入顺序表各元素值：";
    for(int i = 0; i < L.length; i++)
        cin >> L.data[i];
}

//删除有序表中s与t之间的值
bool del_s_t(SeqList &L, ElemType s, ElemType t)
{
    if(t <= s || L.length == 0) return false;
    int i, j;
    for(i = 0; i < L.length && L.data[i] < s; i++);
    if(i >= L.length) return false;
    for(j = i; j < L.length && L.data[j] <= t; j++);
    for(;j < L.length; i++ , j++) L.data[i] = L.data[j];
    L.length = i;
    return true;
}

//删除有序表中其值重复的元素
bool DEL_SAME(SeqList &L)
{
    if(L.length == 0)
    {
        return false;
    }
    int i , j;
    for(i = 0 , j = 1; j < L.length; j++)
    {
        if(L.data[i] != L.data[j])
        {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}

int main()
{
    SeqList L;
   // int e = 0;
   // int value = 0;
    Build(L);
  //  ListDelete(L , 5 , e);
  //  cout << e << endl;
  //  cout<< "元素3的位置为：" << LocateElem(L , 3) <<endl;
  //  DEL_MIN(L , value);
  //  BianLi(L);
  //  Reverse(L);
  //  BianLi(L);
  //  int x = 3;
  //  del_x(L , x);
 //   int s = 1 , t = 5;
 //   del_s_t(L , s , t);
    DEL_SAME(L);
    BianLi(L);
    return 0;
}
