#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
  if (x < 2)
  {
    return false;
  }
  for (int i = 2; i < x / i; i++)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int n, a;
  cin >> n;
  string m;
  while (n--)
  {
    cin >> a;
    m = isPrime(a) ? "Yes" : "No";
    cout << m << endl;
  }

  return 0;
}