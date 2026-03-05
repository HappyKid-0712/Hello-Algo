#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
vector<int> pre;
vector<int> post;
void getPost(int rootIndex, int endIndex, bool isMirror)
{
  if (rootIndex > endIndex)
    return; // 空子树递归结束条件
  int i = rootIndex + 1;
  int j = endIndex;
  if (!isMirror)
  {
    // 找正常的右子树，都大于等于root
    while (i <= endIndex && pre[i] < pre[rootIndex])
    {
      i++;
    }
    while (j > rootIndex && pre[j] >= pre[rootIndex])
    {
      j--;
    }
  }
  else
  {
    // 镜像的情况。
    while (i <= endIndex && pre[i] >= pre[rootIndex])
    {
      i++;
    }
    while (j > rootIndex && pre[j] < pre[rootIndex])
    {
      j--;
    }
  }
  if (i - j != 1)
    return;
  // 后续遍历，左右根
  getPost(rootIndex + 1, j, isMirror);
  getPost(i, endIndex, isMirror);
  post.push_back(pre[rootIndex]);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int N;
  cin >> N;
  pre.resize(N);
  for (auto &it : pre)
  {
    cin >> it;
  }
  getPost(0, N - 1, true);
  if (post.size() < N)
  {
    post.clear();
    getPost(0, N - 1, false);
  }
  if (post.size() == N)
  {
    cout << "YES" << endl;
    for (int i = 0; i < N; i++)
    {
      cout << post[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
  }
  else
  {
    // 两种情况都不匹配
    cout << "NO" << endl;
  }

  return 0;
}