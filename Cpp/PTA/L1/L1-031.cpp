#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
void solve()
{
  int h;
  cin >> h;
  float wReal;
  cin >> wReal;
  float wStand;
  wStand = (float)(h - 100) * 0.9 * 2;
  if (abs(wReal - wStand) < wStand * 0.1)
  {
    cout << "You are wan mei!" << endl;
  }
  else if (wReal >= wStand)
  {
    cout << "You are tai pang le!" << endl;
  }
  else
  {
    cout << "You are tai shou le!" << endl;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int N;
  cin >> N;
  while (N--)
  {
    solve();
  }

  return 0;
}