#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int x;
  cin >> x;
  int cur = 0;
  int n = 0; // 位数
  while (cur < x)
  {
    cur = cur * 10 + 1;
    n++;
  }
  // 不可能有前导0，因为最开始就比x大，所以第一位一定大于0；
  while (true)
  {
    cout << cur / x;
    cur %= x;
    if (cur == 0)
      break;
    cur = cur * 10 + 1;
    n++;
  }
  cout << ' ' << n << endl;
  return 0;
}