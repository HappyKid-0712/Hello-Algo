#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  unordered_map<char, int> mp;
  string str;
  cin >> str;
  transform(str.begin(), str.end(), str.begin(), ::toupper);
  for (auto f : str)
  {
    ++mp[f];
  }
  string tar = "GPLT";
  int i = 0;
  while (true)
  {
    if (mp[tar[i]] != 0)
    {
      cout << tar[i];
      --mp[tar[i]];
      ++i;
      i %= 4;
      continue;
    }
    else if (mp[tar[0]] == 0 && mp[tar[1]] == 0 && mp[tar[2]] == 0 && mp[tar[3]] == 0)
    {
      return 0;
    }
    else
    {
      ++i;
      i %= 4;
    }
  }
  return 0;
}