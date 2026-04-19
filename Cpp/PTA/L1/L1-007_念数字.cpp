#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  map<int, string> mp;
  mp[0] = "ling", mp[1] = "yi", mp[2] = "er", mp[3] = "san", mp[4] = "si", mp[5] = "wu", mp[6] = "liu", mp[7] = "qi", mp[8] = "ba", mp[9] = "jiu";
  int n;
  cin >> n;
  if (n == 0)
  {
    cout << mp[0];
    return 0;
  }
  vector<int> vec;
  bool flag = n > 0 ? true : false;
  n = abs(n);
  while (n != 0)
  {
    vec.push_back(n % 10);
    n /= 10;
    /* code */
  }
  reverse(vec.begin(), vec.end());
  if (!flag)
  {
    cout << "fu" << " ";
  }
  int len = vec.size();
  for (int i = 0; i < len; i++)
  {
    cout << mp[vec[i]];
    if (i != len - 1)
    {
      cout << " ";
    }
  }
  return 0;
}