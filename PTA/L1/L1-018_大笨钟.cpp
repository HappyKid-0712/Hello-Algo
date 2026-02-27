#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int h, m;
  char slash;
  cin >> h >> slash >> m;

  string out = "Dang";
  if (h <= 12)
  {
    cout << "Only " << setw(2) << setfill('0') << h << ':' << setw(2) << setfill('0') << m << ".  Too early to Dang.";
    return 0;
  }
  // h>12的情况
  int len = h - 12;
  if (m != 0)
  {
    len++;
  }
  while (len--)
  {
    cout << out;
  }
  return 0;
}