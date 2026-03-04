#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string str;
  getline(cin, str);
  stringstream ss(str);
  string num;
  int index = 1;
  while (ss >> num)
  {
    if (num == "250")
    {
      cout << index;
      break;
    }
    else
      ++index;
  }

  return 0;
}