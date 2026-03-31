#include <bits/stdc++.h>
using namespace std;

struct NODE
{
  double power;
  vector<int> child;
  int talentTimes = 0;
};
int n;
double r, z;
int solve(vector<NODE> &vec, int root)
{
  int ans;
  queue<int> qu;
  qu.push(root);
  while (!qu.empty())
  {
    root = qu.front();
    qu.pop();

    int sz = qu.size(); // 一层一层来输出
    for (int i = 0; i < sz; i++)
    {
      for (auto it : vec[root].child)
      {
        if (it != 0)
        {
          vec[it].power = vec[root].power * (100 - r) / 100;
          qu.push(it); // 把每一层的孩子加入队列
        }
        else
        {
                }
      }
    }
  }
}
int main()
{
  cin >> n;
  vector<NODE> tree(n);

  for (int i = 0; i < n; i++)
  {
    int amo;
    cin >> amo;
    int child;
    if (amo != 0)
    {
      while (amo--)
      {
        cin >> child;
        tree[i].child.push_back(child);
      }
    }
    else
    {
      cin >> child;
      tree[i].child.push_back(child);
      cin >> tree[i].talentTimes; // 放大的倍数
    }
  }

  return 0;
}