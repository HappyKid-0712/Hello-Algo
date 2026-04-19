#include <bits/stdc++.h>
using namespace std;
int main()
{
  double x, y;
  cin >> x >> y;
  double ans = x / pow(y, 2);
  cout << fixed << setprecision(1) << ans << endl;
  if (ans > 25)
  {
    cout << "PANG";
  }
  else
    cout << "Hai Xing";
  return 0;
}