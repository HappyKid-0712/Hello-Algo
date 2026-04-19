#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int N;
  cin >> N;
  int inputInteger;
  int cntEven = 0, cntOdd = 0;
  while (N--)
  {
    cin >> inputInteger;
    if (inputInteger % 2 == 0)
      ++cntEven;
    else
      ++cntOdd;
  }
  cout << cntOdd << ' ' << cntEven;
  return 0;
}