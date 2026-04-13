#include <bits/stdc++.h>
#define INITSIZE 10
#define ElemType int
using namespace std;

typedef struct
{
  ElemType *data; // 数组空间
  int length;     // 当前数组的长度,相对于下标来说就是最后一个元素的后一个
  int MaxSize;    // 数组最大长度
} Sqlist;

void ListInit(Sqlist &L)
{
  /**
   * @brief 创建顺序表，为表分配空间大小，初始化长度为0，最大长度为INITSIZE
   *
   */
  L.data = (ElemType *)malloc(INITSIZE * sizeof(ElemType));
  L.MaxSize = INITSIZE;
  L.length = 0;
}

void DestroyList(Sqlist &L)
{
  /**
   * @brief 销毁顺序表，清除其在内存的空间
   *
   */
  L.length = 0;
  L.MaxSize = INITSIZE;
  free(L.data);
  L.data = nullptr;
}

bool ListDelete(Sqlist &L, int i, ElemType &e)
{
  /**
   * @brief 删除顺序表下标为i的元素，并将删除的元素返回
   * @param L 操作的数组
   * @param i 删除元素的下标
   * @param e 返回删除的元素
   * @return false表示失败，true表示成功
   */
  if (i < 1 || i > L.length)
  {
    return false;
  }
  e = L.data[i - 1];
  for (int j = i; j < L.length; j++)
  {
    L.data[j - 1] = L.data[j];
  }
  L.length--;
  return true;
}

bool ListInsert(Sqlist &L, int i, ElemType e)
{
  /**
   * @brief 在下标为i-1的位置插入元素e
   * @param L 要操作的数组
   * @param i 插入的位置下标从1开始
   * @param e 插入的元素
   */
  if (L.length >= L.MaxSize) // 该数组是否已经满了
  {
    return false;
  }
  if (i < 1 || i > L.length + 1) // 插入的下标是否合法
  {
    return false;
  }

  for (int j = L.length; j >= i; j--) // 所有元素要往后挪
  {
    L.data[j] = L.data[j - 1];
  }
  L.data[i - 1] = e;
  L.length++; // 插入成功后长度要加一
  return true;
}

int LocateElem(Sqlist &L, ElemType e)
{
  /**
   * @brief 按值查找，找到第一个值等于e的位置，返回位序
   *
   */
  for (int i = 0; i < L.length; i++)
  {
    if (L.data[i] == e)
      return i + 1;
  }
  return 0;
}

// 推荐的写法
bool getElem(Sqlist &L, int i, ElemType &e)
{
  if (i < 1 || i > L.length)
    return false;    // 越界返回失败
  e = L.data[i - 1]; // 将值赋给 e 带出去
  return true;       // 返回成功
}

bool ListResize(Sqlist &L, int NewSize)
{
  /**
   * @brief 动态分配表大小
   *
   */
  if (NewSize < 1)
    return false;
  int *p = L.data;                                    // 将之前分配的空间记录下来
  L.data = (int *)malloc(sizeof(ElemType) * NewSize); // 动态分配新的大小
  L.MaxSize = NewSize;
  L.length = L.length > NewSize ? NewSize : L.length;
  for (int i = 0; i < L.length; i++)
  {
    L.data[i] = p[i];
  }
  free(p);
  return true;
}
int main()
{
  return 0;
}