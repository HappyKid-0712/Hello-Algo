#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// 定义人的结构体
struct Person
{
  char gender = ' '; // M, F 或空
  int father = -1;
  int mother = -1;
};

// 全局变量，100005 是考虑到 ID 范围
vector<Person> tree(100005);
bool visited[100005];

// 核心判断函数
int check(int a, int b)
{
  // 1. 性别检查
  if (tree[a].gender == tree[b].gender)
    return -1;

  // 2. 初始化标记数组
  for (int i = 0; i < 100005; i++)
    visited[i] = false;

  // 3. 第一个人 A 的 BFS：标记 5 代以内所有祖先
  queue<pair<int, int>> q;
  q.push({a, 1}); // {当前 ID, 当前代数}
  visited[a] = true;

  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();

    int id = cur.first;
    int level = cur.second;

    // 如果还没到第 5 代，继续往上找父母
    if (level < 5)
    {
      if (tree[id].father != -1)
      {
        visited[tree[id].father] = true;
        q.push({tree[id].father, level + 1});
      }
      if (tree[id].mother != -1)
      {
        visited[tree[id].mother] = true;
        q.push({tree[id].mother, level + 1});
      }
    }
  }

  // 4. 第二个人 B 的 BFS：检查 5 代以内是否有碰撞
  queue<pair<int, int>> q2;
  q2.push({b, 1});

  while (!q2.empty())
  {
    pair<int, int> cur = q2.front();
    q2.pop();

    int id = cur.first;
    int level = cur.second;

    // 【关键】如果在 A 的祖先标记里找到了此人，说明不可通婚
    if (visited[id])
      return 1;

    if (level < 5)
    {
      if (tree[id].father != -1)
      {
        q2.push({tree[id].father, level + 1});
      }
      if (tree[id].mother != -1)
      {
        q2.push({tree[id].mother, level + 1});
      }
    }
  }

  return 0; // 没撞上，可以成婚
}

int main()
{
  // 优化输入输出
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int id, f, m;
    char g;
    cin >> id >> g >> f >> m;
    tree[id].gender = g;
    tree[id].father = f;
    tree[id].mother = m;
    // 关键：给父母预设性别，防止他们在输入中没有独立行
    if (f != -1)
      tree[f].gender = 'M';
    if (m != -1)
      tree[m].gender = 'F';
  }

  int k;
  cin >> k;
  while (k--)
  {
    int a, b;
    cin >> a >> b;
    int result = check(a, b);
    if (result == -1)
      cout << "Never Mind\n";
    else if (result == 1)
      cout << "No\n";
    else
      cout << "Yes\n";
  }

  return 0;
}