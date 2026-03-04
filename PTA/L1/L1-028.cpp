#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
bool isPrime(int x)
{
  if (x < 2)
    return false;
  if (x == 2 || x == 3)
    return false;
  if (x % 2 == 0)
    return false;
  for (int i = 3; i <= x / i; i++)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
void solve()
{
  int num;
  cin >> num;
  if (isPrime(num))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
};

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