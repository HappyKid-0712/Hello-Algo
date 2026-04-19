#include <bits/stdc++.h>
typedef int Elemtype;
typedef struct DLinkNode
{
  Elemtype data; // 数值域
  DLinkNode *prior, *next;

  DLinkNode(int d, DLinkNode *p = nullptr, DLinkNode *n = nullptr) : data(d), prior(p), next(n) {};
} DLinkNode, *DLinkList;

bool InitDLinkList(DLinkList &L)
{
  L = (DLinkNode *)malloc(sizeof(DLinkNode));
  if (L == nullptr)
    return false;
  L->prior = nullptr;
  L->next = nullptr;
  return true;
}

bool InsertNextDNode(DLinkNode *p, DLinkNode *n)
{
  if (p == nullptr || n == nullptr)
    return false;
  n->next = p->next;
  if (p->next != nullptr)
    p->next->prior = n;
  n->prior = p;
  p->next = n;
  return true;
}

bool DeleteList(DLinkList &L, int i, Elemtype &e)
{
  if (L == nullptr || L->next == nullptr || i < 1)
    return false;
  DLinkNode *p = L;
  int j = 0;
  while (p != nullptr && j < i)
  {
    p = p->next;
    ++j;
  }
  if (p == nullptr)
    return false;

  p->prior->next = p->next;
  if (p->next != nullptr)
    p->next->prior = p->prior;
  e = p->data;
  free(p);
  return true;
}

using namespace std;
int main()
{

  return 0;
}