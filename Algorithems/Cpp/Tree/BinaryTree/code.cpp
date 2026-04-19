#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
对于二叉树来说，一般就是用一个vec去接纳节点，所有创建的节点都该被传入进去。
然后对于节点的组织，其实交给结构体的定义就行了，因为结构体的lchild和rchild已经定义了结构之间的关系了。
这种思想对于很多节点类的数据结构都适用
删除节点不能用erase，因为节点会自动往前走，下标和变化，后面的节点就全乱了，那么删除节点就断开链接就行了。
可以开个stack回收池子去回收节点，然后修改newNodeForVec的算法。
*/
struct node
{
  char val;
  int lchild;
  int rchild;
  node(char val = '0', int lchild = 0, int rchild = 0) : val(val), lchild(lchild), rchild(rchild) {}
};

vector<node> binTreeVec(1, node()); // 一般要初始化一个空节点出来
node binTeeStatic[MAXN];
int idx = 1; // 一般来说下标为0的地方作为空节点。用idx来宏观分配，当然也可以用vec来push

int newNodeForVec(char val)
{
  // 返回节点的下标。
  binTreeVec.push_back(node(val));
  return binTreeVec.size() - 1;
}

int newNodeForStatic(char val)
{
  binTeeStatic[idx] = node(val);
  return idx++;
}

void insertNode(int fatherIndex, int childeIndex, bool LorR)
{
  if (LorR)
  {
    binTreeVec[fatherIndex].lchild = childeIndex;
  }
  else
    binTreeVec[fatherIndex].rchild = childeIndex;
}

int createNewTree(deque<char> &valQue) // 传入一个要处理的数值队列
{
  int root = newNodeForVec(valQue.front());
  valQue.pop_front(); // 取头节点出来

  queue<int> qu; // 遍历用的队列
  qu.push(root);
  while (!qu.empty())
  {
    int curr = qu.front();
    qu.pop();
    if (!valQue.empty() && valQue.front() != '0') // 零代表是空的，没有这个数值
    {
      int lidx = newNodeForVec(valQue.front()); // 分开写，写在一起会爆炸
      binTreeVec[curr].lchild = lidx;
      valQue.pop_front();
      qu.push(binTreeVec[curr].lchild);
    }
    else if (!valQue.empty())
    {
      valQue.pop_front();
    }

    if (!valQue.empty() && valQue.front() != '0')
    {
      int ridx = newNodeForVec(valQue.front());
      binTreeVec[curr].rchild = ridx;
      valQue.pop_front();
      qu.push(binTreeVec[curr].rchild);
    }
    else if (!valQue.empty())
    {
      valQue.pop_front();
    }
  }
  return root;
}

void printPreTree(int root)
{
  if (root == 0)
    return;
  cout << binTreeVec[root].val;
  printPreTree(binTreeVec[root].lchild);
  printPreTree(binTreeVec[root].rchild);
}

void printQueTree(int root)
{
  if (root == 0)
    return;
  queue<int> qu;
  qu.push(root);
  while (!qu.empty())
  {
    int curr = qu.front();
    qu.pop();
    cout << binTreeVec[curr].val;
    if (binTreeVec[curr].lchild != 0)
    {
      qu.push(binTreeVec[curr].lchild);
    }
    if (binTreeVec[curr].rchild != 0)
    {
      qu.push(binTreeVec[curr].rchild);
    }
  }
}

int main()
{
  deque<char> dque = {'E', 'B', 'G', 'A', 'D', 'F', 'I', '0', '0', 'C', '0', '0', 'H', '0'};
  int root = createNewTree(dque);
  printPreTree(root); // 前序遍历
  cout << endl;
  printQueTree(root); // BFS
  cout << endl;
}