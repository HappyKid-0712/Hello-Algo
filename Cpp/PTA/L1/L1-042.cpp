#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
string toDateString(int x, int len)
{
  string s = to_string(x);
  if (s.size() < len)
    s = string(len - s.size(), '0') + s;
  return s;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int day, month, year;
  char tmp;
  cin >> month >> tmp >> day >> tmp >> year;
  string dayStr, monthStr, yearStr;
  dayStr = toDateString(day, 2);
  monthStr = toDateString(month, 2);
  yearStr = toDateString(year, 4);
  cout << yearStr << '-' << monthStr << '-' << dayStr;
  return 0;
}