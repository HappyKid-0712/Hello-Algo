#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  string s;
  cin >> s;
  bool isFu = false;
  bool isOu = false;
  int count = 0;
  int len = s.length();
  if (s[0] == '-')
  {
    isFu = true;
    len--;
  }
  int lastDigit = s[s.length() - 1] - '0';
  if (lastDigit % 2 == 0)
  {
    isOu = true;
  }
  for (auto it : s)
  {
    if (it == '2')
    {
      count++;
    }
  }
  float res = (float)count / len;
  if (isFu)
  {
    res *= 1.5;
  }
  if (isOu)
  {
    res *= 2;
  }
  res *= 100;
  printf("%.2f%%\n", res);
  return 0;
}