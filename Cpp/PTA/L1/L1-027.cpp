#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string telNumber;
  cin >> telNumber;
  vector<char> vec;
  for (char it : telNumber)
  {
    vec.push_back(it);
  }
  sort(vec.begin(), vec.end(), greater<char>());
  // 去重
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  // print
  cout << "int[] arr = new int[]{";
  for (int i = 0; i < vec.size(); i++)
  {
    if (i > 0)
    {
      cout << ',';
    }
    cout << vec[i];
  }
  cout << "};" << endl;
  cout << "int[] index = new int[]{";
  for (int i = 0; i < telNumber.size(); i++)
  {
    if (i > 0)
    {
      cout << ',';
    }
    auto it = find(vec.begin(), vec.end(), telNumber[i]);
    cout << it - vec.begin();
  }
  cout << "};";
  return 0;
}