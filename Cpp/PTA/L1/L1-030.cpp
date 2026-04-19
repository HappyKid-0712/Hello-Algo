#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
struct STUDENT
{
  int sex;
  string name;
};
bool vis[MAXN];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int N;
  cin >> N;
  vector<STUDENT> classPeople(N);
  for (auto &it : classPeople)
  {
    cin >> it.sex >> it.name;
  }
  for (int i = 0; i < classPeople.size(); i++)
  {
    for (int j = classPeople.size() - 1; j > i; j--)
    {
      if ((classPeople[i].sex != classPeople[j].sex) && !vis[j])
      {
        cout << classPeople[i].name << ' ' << classPeople[j].name << endl;
        vis[j] = true;
        break;
      }
    }
    }

  return 0;
}