#include <bits/stdc++.h>
using namespace std;
int main()
{
  double x, y;
  cin >> x >> y;
  double ans = pow(x / y, 2);
  cout << ans << endl;
  if (ans > 25)
  {
    cout << "pang";
  }
  else
    cout << "Hai Xing";
  return 0;
}