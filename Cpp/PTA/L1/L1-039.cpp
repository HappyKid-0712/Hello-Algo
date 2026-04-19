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
  string str;
  cin.ignore();
  getline(cin, str);
  int cols = (str.size() + N - 1) / N;
  for (int r = 0; r < N; ++r)
  {
    for (int c = 0; c < cols; ++c)
    {
      int index = (cols - 1 - c) * N + r; // 加r就是下去的位置。
      if (index < str.size())
      {
        cout << str[index];
      }
      else
      {
        cout << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}