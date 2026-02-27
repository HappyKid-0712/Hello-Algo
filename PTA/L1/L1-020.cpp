#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int N;
  cin >> N;
  int k, M;
  unordered_map<string, bool> mp;
  string uid;
  while (N--)
  {
    cin >> k;
    // 初始化 输入数据
    int oringinal_k = k;
    while (k--)
    {
      cin >> uid;
      if (oringinal_k > 1)
      {
        mp[uid] = true;
      }
    }
  }

  // M次查询
  cin >> M;

  vector<string> res;
  while (M--)
  {
    cin >> uid;
    if (mp.find(uid) == mp.end())
    {
      res.push_back(uid);
      mp[uid] = true;
    }
  }
  if (res.empty())
  {
    cout << "No one is handsome";
    return 0;
  }
  for (int i = 0; i < res.size(); i++)
  {
    if (i > 0)
    {
      cout << ' ';
    }
    cout << res[i];
  }

  return 0;
}