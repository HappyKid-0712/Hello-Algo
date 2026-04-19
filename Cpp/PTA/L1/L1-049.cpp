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
  vector<int> schoolNumber(N, 0);
  int numTeam; // 存储学校的队伍数
  for (int &it : schoolNumber)
  {
    cin >> numTeam;
    it = numTeam * 10;
  }
  int set = 0;
  // 分配原理就是挨着减，如果有个减完了就跳
  int curr = 0;  // 从第一个学校开始排位置
  int pre = -1;  // 上一个学校
  int restN = N; // 剩余的学校
  // 创建一个数组来存储每个学校的座位号
  vector<vector<int>> res(N); // 创建二维数组存储结果
  while (true)
  {
    if (schoolNumber[curr] != 0)
    {
      // 当前学校有人数才进入，没人数说明排完了
      if (curr != pre)
      {
        // 上一个学校不是自己，说明正常存set就行
        ++set;
        res[curr].push_back(set);
        --schoolNumber[curr];
        pre = curr;
        if (schoolNumber[curr] == 0)
        {
          --restN;
        }
      }
      else if (curr == pre)
      {
        set += 2;
        res[curr].push_back(set);
        --schoolNumber[curr];
        if (schoolNumber[curr] == 0)
        {
          --restN;
        }
      }
    }
    ++curr;
    curr %= N;
    if (restN == 0)
    {
      break;
    }
  }
  for (int i = 0; i < res.size(); i++)
  {
    cout << "#" << i + 1 << endl;
    for (int j = 0; j < res[i].size(); j++)
    {
      if (j > 0)
      {
        cout << ' ';
      }
      cout << res[i][j];
      if ((j + 1) % 10 == 0 || j == res[i].size() - 1)
      {
        cout << endl;
      }
    }
  }
  return 0;
}