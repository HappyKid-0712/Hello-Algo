#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string a;
  int b;
  cin >> a >> b;
  int t = 0;
  string res = "";
  for (auto it : a)
  {
    t = t * 10 + (it - '0'); // 获得当前的除数
    if (t >= b)
    {
      res += t / b + '0';
      t = t % b;
    }
    else
      res += '0';
  }
  cout << res << endl
       << t;
  return 0;
}