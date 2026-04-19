#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e4 + 5;
char seaMap[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
bool isLand(pair<int, int> node)
{
  queue<pair<int, int>> qu;
  qu.push(node);
  vis[node.first][node.second] = true; // 去队列就相当于访问了；
  bool hasHighLand = false;            // 最开始没陆地

  while (!qu.empty())
  {
    int x = qu.front().first;
    int y = qu.front().second;
    bool isHighLand = true; // 假设是高地
    qu.pop();

    for (int i = 0; i < 4; i++)
    {
      if (seaMap[x + dx[i]][y + dy[i]] == '.') // 有海了说明不是高地
      {
        isHighLand = false;
        break;
      }
    }

    if (isHighLand)
    {
      hasHighLand = true;
    }

    for (int i = 0; i < 4; i++)
    {
      if (seaMap[x + dx[i]][y + dy[i]] == '#' && !vis[x + dx[i]][y + dy[i]]) // 是陆地并且没有被访问过，就存进队列
      {
        qu.push({x + dx[i], y + dy[i]});
        vis[x + dx[i]][y + dy[i]] = true; // 入队列就要标记被访问。
      }
    }
  }
  return !hasHighLand;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> N;
  // 扩大一圈
  for (int i = 0; i <= N + 1; i++)
  {
    for (int j = 0; j <= N + 1; j++)
    {
      seaMap[i][j] = '.';
    }
  }
  // 输入初始化
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> seaMap[i][j];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (seaMap[i][j] == '#' && !vis[i][j]) // 是陆地，并且所在的岛屿里面没有高地
      {
        if (isLand({i, j}))
          ++cnt;
      }
    }
  }
  cout << cnt;
  return 0;
}