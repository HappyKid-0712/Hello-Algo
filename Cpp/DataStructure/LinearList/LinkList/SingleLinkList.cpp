#include <bits/stdc++.h>
#define Elemtype int
typedef struct LinkNode
{
  Elemtype data;  // 数值域
  LinkNode *next; // 指针域
} LinkNode, *LinkList;

/**
 * @brief 初始化一个带头节点的链表，使其指针域为空，数值域为-1
 *
 * @param L 传入的头节点
 * @return true 创建成功
 * @return false 创建失败
 */
bool InitList(LinkList &L)
{
  LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));

  if (p == nullptr) // 说明分配空间失败，可能是空间不足的原因
    return false;

  p->next = nullptr;
  p->data = -1;
  L = p;
  return true;
}

/**
 * @brief Get the Length object
 *
 * @param L 传入的长度
 * @return int 返回的长度
 */
int getLength(LinkList L)
{
  int ListLength = 0;
  if (L == nullptr)
    return 0;
  LinkNode *p = L->next;
  while (p != nullptr)
  {
    p = p->next;
    ++ListLength;
  }
  return ListLength;
}

/**
 * @brief Get the Elem object
 *
 * @param L 传入的链表
 * @param i 要查找的位序
 * @return LinkNode* 返回得到的节点指针
 */
LinkNode *getElem(LinkList &L, int i)
{
  if (i < 1 || L == nullptr) // 对非法情况进行判断
    return nullptr;

  LinkNode *p = L;
  int j = 0;                    // 带头节点的链表下标与位序一致，头节点表示第零个元素
  while (p != nullptr && j < i) // loop到i-1的位置，因为这个循环会多做一次，那么结束的条件就是j==i
  {
    p = p->next;
    ++j;
  }
  return p; // 超了自然是nullptr，不用特判
}

/**
 * @brief 按值查找
 *
 * @param L 传入的链表
 * @param e 查询的值
 * @return LinkNode* 返回查到的节点
 */
LinkNode *locateElem(LinkList &L, Elemtype e)
{
  if (L == nullptr || L->next == nullptr)
    return nullptr;
  LinkNode *p = L->next;
  while (p != nullptr && p->data != e)
  {
    p = p->next;
  }
  return p;
}

/**
 * @brief 在位序为i的位置插入一个节点
 *
 * @param L LinkList的链表
 * @param i 插入的位序
 * @param e 插入的值
 * @return true
 * @return false
 */
bool ListInsert(LinkList &L, int i, Elemtype e)
{
  if (L == nullptr)
    return false;
  int j = 0;
  LinkNode *p = L;
  while (p != nullptr && j < i - 1) // 找到前一个节点
  {
    p = p->next;
    ++j;
  }

  if (p == nullptr) // 如果插的太远就返回false
    return false;
  LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

bool ListDelete(LinkList &L, int i, Elemtype &e)
{
  if (L == nullptr || L->next == nullptr || i < 1)
    return false;
  int j = 0;
  LinkNode *p = L;
  while (p->next != nullptr && j < i - 1)
  {
    p = p->next;
    ++j;
  }

  if (p->next == nullptr) // 删的位置不合法
    return false;
  LinkNode *s = p->next;
  e = s->data;
  p->next = s->next;

  free(s);
  return true;
}

using namespace std;
int main()
{

  return 0;
}