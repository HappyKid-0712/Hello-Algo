#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
struct Node
{
  int key;
  int next;
} nodes[MAXN];
bool vis[MAXN];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  vector<int> kept, deleted;
  int L, N;
  cin >> L >> N;
  for (int i = 0; i < N; i++)
  {
    int curr, key, next;
    cin >> curr >> key >> next;
    nodes[curr].key = key;
    nodes[curr].next = next;
  }
  int k = L;
  while (k != -1)
  {
    if (!vis[abs(nodes[k].key)])
    {
      vis[abs(nodes[k].key)] = true;
      kept.push_back(k);
    }
    else
    {
      deleted.push_back(k);
    }
    k = nodes[k].next;
  }

  // 直接跟进原有的下标进行输出就行了，不用去修改原有的坐标，只有输出值的时候去nodes里面找值、
  for (size_t i = 0; i < kept.size(); i++)
  {
    cout << setfill('0') << setw(5) << kept[i] << ' ' << nodes[kept[i]].key << ' ';
    if (i == kept.size() - 1)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << setfill('0') << setw(5) << kept[i + 1] << endl;
    }
  }

  // 输出删除的链表（必须先判断是否为空）
  // 有可能会有全部是独立的情况，所以要注意。
  if (!deleted.empty())
  {
    for (size_t i = 0; i < deleted.size(); i++)
    {
      cout << setfill('0') << setw(5) << deleted[i] << ' ' << nodes[deleted[i]].key << ' ';
      if (i == deleted.size() - 1)
      {
        cout << -1 << endl;
      }
      else
      {
        cout << setfill('0') << setw(5) << deleted[i + 1] << endl;
      }
    }
  }
  return 0;
}