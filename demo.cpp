#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  if (!(cin >> N >> M))
    return 0;

  queue<int> q;
  map<int, bool> mp; // ✅ 1. 字典必须放在循环外面，记住所有状态
  int cnt = 0;

  while (M--)
  {
    int word;
    cin >> word;

    // ✅ 2. 使用 mp.count() 查找键是否存在。0 表示没找到。
    if (mp.count(word) == 0)
    {
      // ✅ 3. 内存容量用 N，而不是写死的 3
      if (q.size() == N)
      {
        // ✅ 4. 淘汰最早进入队列的单词
        mp.erase(q.front()); // 直接传 key 给 erase 即可，不需要 find
        q.pop();
      }

      // 将新单词加入内存
      q.push(word);
      mp[word] = true;
      ++cnt;
    }
  }

  cout << cnt << endl;
  return 0;
}