#include <bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int x, int y)
{
  return y == 0 ? abs(x) : gcd(y, x % y);
}
struct Fraction
{
  ll up, down; // 分子
  /* data */
  void reduce()
  {
    if (down < 0)
    {
      up -= up;
      down -= down;
    } // 将底部的符号移到上面去
    if (up == 0)
    {
      down = 1;
    }
    else
    {
      ll d = gcd(abs(up), down);
      up /= d;
      down /= d;
    }
  }
  Fraction(ll u = 0, ll d = 1)
  {
    up = u;
    down = d;
    reduce();
  }
  Fraction operator+(const Fraction &f) const
  {
    return Fraction(up * f.down + f.up * down, down * f.down);
  }
};

int main()
{
  int N;
  ll n, d;
  char slash;
  std::cin >> N;
  Fraction sum(0, 1);
  for (int i = 0; i < N; i++)
  {
    std::cin >> n >> slash >> d;
    sum = sum + Fraction(n, d);
  }
  // init

  // 输出
  // 先输出整数部分
  ll integer_part = sum.up / sum.down;
  ll rem_up = sum.up % sum.down; // 分子
  if (integer_part == 0 && rem_up == 0)
  {
    // 判断和为0的情况
    cout << 0 << endl;
  }
  else
  {
    // 这段代码写的好,把输出拆分开了
    if (integer_part != 0)
    {
      cout << integer_part;
      if (rem_up != 0)
        cout << " ";
    }
    if (rem_up != 0)
    {
      cout << rem_up << "/" << sum.down;
    }
    cout << endl;
  }
  return 0;
}