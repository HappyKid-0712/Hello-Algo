#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define MAXV 505
#define INF 0x3f3f3f3f
int G[MAXV][MAXV];
int N, M, S, D;
void Dijkstra()
{
  cin >> N >> M >> S >> D;
  int weight[N], team[N]; // 到达该节点能获得最大的人数
  int dist[N], pre[N], num[N];
  bool vis[N];
  for (int i = 0; i < N; i++)
  {
    cin >> team[i];
  }
  for (int i = 0; i < M; i++)
  {
    // 输入，初始化
    int x, y, e;
    cin >> x >> y >> e;
    G[x][y] = G[y][x] = e;
  }
  // 开始初始化
  for (int i = 0; i < N; i++)
  {
    dist[i] = INF;
    vis[i] = 0;
    pre[i] = -1;
    weight[i] = 0;
    num[i] = 0;
  } // 初始化全部改成都不知道，这样进循环就相当于，从0开始一个一个找进去。
  dist[S] = 0;
  num[S] = 1; // 自己到自己有一条
  weight[S] = team[S];
  for (int i = 0; i < N; i++)
  {
    // 寻找当前集合里面最短的，然后更新集合，之前确认最短的集合路径就不修改了
    int mindist = INF;
    int k = -1;
    for (int j = 0; j < N; j++)
    {
      if (!vis[j] && dist[j] < mindist)
      {
        // 找到当前集合里面路径最短的，以它为起点，从图里面添加新点进来。
        mindist = dist[j];
        k = j;
      }
    }
    if (k == -1)
      break;
    vis[k] = 1; // 代码这个点已经要被确认了
    for (int j = 0; j < N; j++)
    {
      // 从图里面找，新点进来，然后更新集合内部的距离
      if (!vis[j] && G[k][j] < INF && dist[k] + G[k][j] < dist[j])
      {
        num[j] = num[k];
        weight[j] = weight[k] + team[j];
        dist[j] = dist[k] + G[k][j]; // 更新集合内部的最短距离，并且有不在集合里面的，顺便就加进来了。
        pre[j] = k;
      }
      else if (!vis[j] && G[k][j] < INF && dist[k] + G[k][j] == dist[j])
      {
        num[j] += num[k]; // 否则新的j就等于本身加上K，因为j可以是原集合里面有的，也可以是外部的，如果是外部的，那么num[j]==0,如果是内部的，那说明本身就有路径数。
        if (weight[k] + team[j] > weight[j])
        {
          weight[j] = weight[k] + team[j];
          pre[j] = k;
        }
        // 如果距离相等，优先和最大的上
      }
    }
  }
  cout << num[D] << ' ' << weight[D] << endl;
  stack<int> st;
  int curr = D;
  while (curr != -1)
  {
    st.push(curr);
    curr = pre[curr];
  }
  while (!st.empty())
  {
    cout << st.top();
    st.pop();
    if (st.size() > 0) // 这里容易错，注意，如果倒数第二个pop后，size==1，就不输出‘ ’
    {
      cout << ' ';
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  memset(G, INF, sizeof(G));
  Dijkstra();
  return 0;
}