#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
string solve(string str)
{
  string tmp = str;
  for (char f : str)
  {
    if (f < '0' || f > '9')
    {
      tmp = '?';
      break;
    }
    if (stoi(str) < 1 || stoi(str) > 1000)
    {
      tmp = '?';
      break;
    }
  }
  return tmp;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string A, B;
  cin >> A;
  getline(cin, B);
  B.erase(B.begin(), B.begin() + 1);
  A = solve(A);
  B = solve(B);
  cout << A << " + " << B << " = ";
  if (A != "?" && B != "?")
  {
    cout << stoi(A) + stoi(B);
  }
  else
  {
    cout << "?";
  }
  return 0;
}