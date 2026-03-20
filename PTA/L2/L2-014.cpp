#include <bits/stdc++.h>
using namespace std;
int len;
vector<int> rail;
vector<int> train;
int main()
{
  cin >> len;
  train.resize(len);
  for (auto &it : train)
  {
    cin >> it;
  }

  for (auto val : train)
  {
    auto it = upper_bound(rail.begin(), rail.end(), val); // 找到第一个大于x的位置
    if (it == rail.end())
    {
      rail.push_back(val);
    }
    else
    {
      *it = val;
    }
  }
  cout << rail.size();
  return 0;
}