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
  while (N--)
  {
    string name;
    int huxi, maibo;
    cin >> name >> huxi >> maibo;
    if ((huxi < 15 || huxi > 20) || (maibo < 50 || maibo > 70))
    {
      cout << name << endl;
    }
  }

  return 0;
}