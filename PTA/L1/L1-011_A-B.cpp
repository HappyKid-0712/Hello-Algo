#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  string a, b;
  getline(cin, a); // 包含空格的输入
  getline(cin, b);
  unordered_map<char, bool> mp;
  for (auto it : b)
  {
    mp[it] = true;
  }
  string result = "";
  for (char f : a)
  {
    if (mp.find(f) == mp.end())
    {
      result += f;
    }
  }
  cout << result << endl;
  return 0;
}