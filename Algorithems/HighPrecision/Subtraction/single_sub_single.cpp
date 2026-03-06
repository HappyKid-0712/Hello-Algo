#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int a, b, n; // a是被除数，b是除数，n是精确的位数。
  cin >> a >> b >> n;

  int t = a % b;
  string res;
  while (n--)
  {
    res += (t * 10) / b + '0';
    t = (t * 10) % b;
  }
  cout << a << " / " << b << " = " << a / b << "." << res;
  return 0;
}