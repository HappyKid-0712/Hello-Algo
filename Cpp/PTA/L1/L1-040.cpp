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
    char sex;
    double h, res;
    cin >> sex >> h;
    if (sex == 'M')
    {
      cout << fixed << setprecision(2) << h / (1.09) << endl;
    }
    else
    {
      cout << fixed << setprecision(2) << h * (1.09) << endl;
    }
  }

  return 0;
}