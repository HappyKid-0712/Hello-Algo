#include <bits/stdc++.h>
using namespace std;
int n, k, m;
priority_queue<double> stuPriQue;

int main()
{
  cin >> n >> k >> m;
  for (int i = 0; i < n; i++)
  {
    vector<int> judgeVec(k);
    for (auto &it : judgeVec)
    {
      cin >> it;
    }
    sort(judgeVec.begin(), judgeVec.end());
    judgeVec.erase(judgeVec.begin());
    judgeVec.erase(judgeVec.end() - 1);

    stuPriQue.push((double)accumulate(judgeVec.begin(), judgeVec.end(), 0) / judgeVec.size());
  }

  vector<double> ans(m);
  for (int i = 0; i < m; i++)
  {
    ans[i] = stuPriQue.top();
    stuPriQue.pop();
  }

  for (int i = m - 1; i >= 0; i--)
  {
    if (i < m - 1)
    {
      cout << ' ';
    }
    cout << fixed << setprecision(3) << ans[i];
  }
  return 0;
}