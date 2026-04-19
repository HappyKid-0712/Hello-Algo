#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int g_graph[505][505]; // 使用邻接矩阵，500的数据量足够
bool g_vis[505];
bool g_isLost[505];

// 使用 DFS 遍历整个连通块
void dfs(int u)
{
  g_vis[u] = true;
  for (int v = 0; v < N; v++)
  {
    if (g_graph[u][v] && !g_vis[v] && !g_isLost[v])
    {
      dfs(v);
    }
  }
}

int countComponents()
{
  fill(g_vis, g_vis + N, false);
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    if (!g_isLost[i] && !g_vis[i])
    {
      cnt++;
      dfs(i); // 一次 DFS 标记完整个连通分量
    }
  }
  return cnt;
}

int main()
{
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++)
  {
    int u, v;
    scanf("%d %d", &u, &v);
    g_graph[u][v] = g_graph[v][u] = 1; // 无向图
  }

  int preCnt = countComponents();

  scanf("%d", &K);
  for (int k = 1; k <= K; k++)
  {
    int lostCity;
    scanf("%d", &lostCity);
    g_isLost[lostCity] = true;

    int currCnt = countComponents();

    // 如果当前连通块数量 > 之前的数量 + 1 (加1是因为丢了一个点本身会少一个块)
    // 或者更简单的逻辑：如果剩下城市的连通块增加了
    if (currCnt > preCnt)
    {
      printf("Red Alert: City %d is lost!\n", lostCity);
    }
    else
    {
      printf("City %d is lost.\n", lostCity);
    }

    preCnt = currCnt; // 实时更新基准

    if (k == N)
    {
      printf("Game Over.\n");
    }
  }

  return 0;
}