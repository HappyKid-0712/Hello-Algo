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
  char letter;
  cin >> N >> letter;
  string tar;
  string tmp;
  getline(cin, tmp);
  cout << tmp;
  getline(cin, tar);
  int len = N - tar.size();
  if (len < 0)
  {
    cout << tar.substr(tar.size() - N);
  }
  else
  {
    for (int i = 0; i < len; i++)
    {
      cout << letter;
    }
    cout << tar;
  }

  return 0;
}