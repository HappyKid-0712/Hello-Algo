#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int lenVec, lenSet;
  cin >> lenVec;
  vector<set<int>> vec(lenVec);
  for (int i = 0; i < lenVec; i++)
  {
    cin >> lenSet;
    while (lenSet--)
    {
      int num;
      cin >> num;
      vec[i].insert(num);
    }
  }
  double res;
  int T;
  cin >> T;
  while (T--)
  {
    int A, B;
    cin >> A >> B;
    A--, B--;
    int cnt = 0;
    if (vec[A].size() > vec[B].size())
    {
      swap(A, B);
    }

    for (auto it : vec[A])
    {
      if (vec[B].count(it) != 0)
      {
        //!=0说明有交集
        ++cnt;
      }
    }
    int rest = vec[A].size() + vec[B].size() - cnt;
    res = (double)cnt / rest * 100;
    cout << fixed << setprecision(2) << res << '%' << endl;
  }

  return 0;
}