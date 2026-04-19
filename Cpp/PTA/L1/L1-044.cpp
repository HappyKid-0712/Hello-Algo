#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int k;
  cin >> k;
  string str;
  int cnt = 0;
  while (true)
  {
    cin >> str;
    if (str == "End")
      break;
    if (cnt != k)
    {
      if (str == "Bu")
        cout << "JianDao" << endl;
      else if (str == "JianDao")
        cout << "ChuiZi" << endl;
      else if (str == "ChuiZi")
        cout << "Bu" << endl;
    }
    else
    {
      cout << str << endl;
    }
    ++cnt %= k + 1;
  }

  return 0;
}