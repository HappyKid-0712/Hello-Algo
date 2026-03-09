#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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

int createNewTree(deque<char> &valQue)
{
  int root = newNodeForVec(valQue.front());
  valQue.pop_front();
  queue<int> qu;
  qu.push(root);
  while (!qu.empty())
  {
    int curr = qu.front();
    qu.pop();
    if (!valQue.empty() && valQue.front() != '0')
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
  printPreTree(root);
  cout << endl;
  printQueTree(root);
  cout << endl;
}