#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int num, den;
  cin >> num >> den;
  cout << num << '/';
  if (den < 0)
  {
    cout << "(" << den << ")";
  }
  else if (den >= 0)
  {
    cout << den;
  }
  cout << "=";
  if (den == 0)
  {
    cout << "Error";
  }
  else
  {
    double res = (float)num / den;
    cout << fixed << setprecision(2) << res;
  }
  return 0;
}