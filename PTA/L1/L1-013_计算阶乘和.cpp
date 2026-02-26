#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll func(int n)
{
  return n == 1 ? 1 : n * func(n - 1);
}
int main()
{
  ll N, sum = 0;
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    sum += func(i);
  }
  cout << sum;
  return 0;
}