#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, num, t;
  cin >> n;
  map<int, int> mp;
  while (n--)
  {
    cin >> t;
    while (t--)
    {
      cin >> num;
      mp[num]++;
    }
  }
  int max_key, max_cnt = 0;
  for (auto it : mp)
  {
    if (it.second > max_cnt)
    {
      max_cnt = it.second;
      max_key = it.first;
    }
    else if (it.second == max_cnt)
    {
      if (max_key < it.first)
      {
        max_cnt = it.second;
        max_key = it.first;
      }
    }
  }
  cout << max_key << ' ' << max_cnt;
  return 0;
}