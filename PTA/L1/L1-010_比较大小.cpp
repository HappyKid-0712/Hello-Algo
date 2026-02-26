#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  vector<int> vec(3, 0);
  for (auto &it : vec)
  {
    cin >> it;
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i];
    if (i != vec.size() - 1)
    {
      cout << "->";
    }
  }
  return 0;
}