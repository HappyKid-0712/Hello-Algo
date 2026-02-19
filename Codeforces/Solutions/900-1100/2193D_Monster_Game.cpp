#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> veca, vecb;
int diffic, n, score;
void solve()
{
  cin >> n;
  score = 0, diffic = 0; // 总分初始化为0，难度也最开始为0；
  veca.resize(n + 1), vecb.resize(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> veca[i];
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> vecb[i];
  }

  sort(veca.begin(), veca.end());

  cout << score << endl;
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}