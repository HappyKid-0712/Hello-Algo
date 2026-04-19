#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int H;
  cin >> H;
  float w;
  w = (float)(H - 100) * 0.9;
  // print
  cout << fixed << setprecision(1);
  cout << w * 2;
  return 0;
}