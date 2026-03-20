#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string, int> g_mp;
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string UID;
    cin >> UID;
    g_mp[UID] = 0;
  }

  map<string, int> ans_mp;
  cin >> m;
  int sum = 0;

  for (int i = 0; i < m; i++)
  {
    string UID;
    int likeCnt;
    cin >> UID >> likeCnt;
    if (g_mp.find(UID) == g_mp.end()) // 标记出现在关注列表没有
    {
      ans_mp[UID] = likeCnt;
    }
    sum += likeCnt;
  }

  vector<string> ans;
  double avergaLikeCnt = sum / m;
  for (auto it : ans_mp)
  {
    if (it.second > avergaLikeCnt)
    {
      ans.push_back(it.first);
    }
  }

  if (ans.empty())
  {
    cout << "Bing Mei You";
  }
  else
  {
    for (auto &it : ans)
    {
      cout << it << endl;
    }
  }
  return 0;
}