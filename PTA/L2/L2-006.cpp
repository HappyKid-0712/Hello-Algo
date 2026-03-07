#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int len;
vector<int> pre, post, mid;
int pos[MAXN];
vector<vector<int>> levels(MAXN);
int max_dept = 0;
vector<int> getInput(int len)
{
  // 从一开始的，下标范围为【1-len】
  vector<int> res(len + 1);
  for (int i = 1; i <= len; i++)
  {
    cin >> res[i];
  }
  return res;
}

void preTravel(int left, int right, int st, int end, int depths)
{
  if (left > right)
    return;
  int root = post[end];
  int k = pos[post[end]];
  int lenLeft = k - left;
  int lenRight = right - k;
  levels[depths].push_back(root);
  max_dept = max(max_dept, depths);
  preTravel(left, k - 1, st, end - lenRight - 1, depths + 1);
  preTravel(k + 1, right, st + lenLeft, end - 1, depths + 1);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> len;
  post = getInput(len);
  mid = getInput(len);
  for (int i = 1; i <= len; i++)
  {
    pos[mid[i]] = i;
  }
  preTravel(1, len, 1, len, 1);
  bool first = true;
  for (int i = 1; i <= max_dept; i++)
  {
    for (auto it : levels[i])
    {
      if (!first)
        cout << " ";
      cout << it;
      first = false;
    }
  }
  return 0;
}