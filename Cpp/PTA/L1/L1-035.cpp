#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  vector<string> vec;
  string name;
  while (true)
  {
    cin >> name;
    if (name == ".")
    {
      break;
    }
    vec.push_back(name);
  }
  if (vec.size() >= 14)
  {
    cout << vec[1] << " and " << vec[13] << " are inviting you to dinner...";
  }
  else if (vec.size() >= 2)
  {
    cout << vec[1] << " is the only one for you...";
  }
  else if (vec.size() < 2)
  {
    cout << "Momo... No one is for you ...";
  }

  return 0;
}