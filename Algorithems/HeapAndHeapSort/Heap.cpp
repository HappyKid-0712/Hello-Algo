#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 将传入的元素向下调整为堆堆形式
 *
 * @param vec 传入的数组参数，要求下标从1开始
 * @param k 要向下调整的元素下标
 * @param n 当前未调整的数组长度，用于判断是否到了叶子节点
 */
void downAdjust(vector<int> &vec, int k, int n)
{
  int i = k, j = i * 2; // 保存当前节点和它的左节点
  while (j <= n)        // 如果左孩子都大于最后一个元素了，说明当前节点是叶子节点不需要调整了
  {
    if (j + 1 <= n && vec[j] < vec[j + 1]) // 如果有右节点就保存较大的那个
      ++j;
    if (vec[i] < vec[j])
    {
      swap(vec[i], vec[j]); // 交换
      i = j;                // 递归到下一个较大的节点
      j = i * 2;
    }
    else // 如果比自己的子树都大，说明当前已经调整完成
    {
      break;
    }
  }
}

/**
 * @brief Set the Heap object
 *
 * @param vec 传入要建立的堆数组,下标要从一开始
 * @param n 所在数组的长度，为后续递归做准备
 * @return 无返回值
 */
void heapSort(vector<int> &vec, int n)
{
  // 建堆
  for (int i = n / 2; i >= 1; i--)
  {
    downAdjust(vec, i, n);
  }
  // 排序
  for (int i = n; i >= 2; i--)
  {
    // i表示当前堆的最后一个元素
    swap(vec[1], vec[i]); // 每次将第一个和最后一个交换，因为堆结构保证了root为最大的，如何将第一个元素向下调整，但是对应的堆大小要减1
    downAdjust(vec, 1, i - 1);
  }
}
void printfVec(vector<int> &vec)
{
  int len = vec.size();
  for (int i = 1; i < vec.size(); i++)
  {
    if (i > 1)
    {
      cout << ' ';
    }
    cout << vec[i];
  }
  cout << endl;
}
int main()
{
  vector<int> demoVec(11);
  mt19937 rng(random_device{}());
  uniform_int_distribution<int> dist(1, 100);

  generate(demoVec.begin() + 1, demoVec.end(), [&]()
           { return dist(rng); });
  printfVec(demoVec);
  heapSort(demoVec, 10);
  printfVec(demoVec);
  return 0;
}