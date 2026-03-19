#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

// 全局变量
vector<int> heap;
map<int, int> pos; // 记录值到下标的映射
int N, M;

/**
 * @brief 向上调整（用于顺序插入建堆）
 * @param i 当前插入元素的下标
 */
void upAdjust(int i)
{
  while (i > 1)
  {
    int parent = i / 2;
    if (heap[i] < heap[parent])
    {
      swap(heap[i], heap[parent]);
      i = parent;
    }
    else
    {
      break;
    }
  }
}

void printResult(bool condition)
{
  if (condition)
    cout << "T" << endl;
  else
    cout << "F" << endl;
}

int main()
{
  // 1. 输入数据并动态建堆
  if (!(cin >> N >> M))
    return 0;

  heap.resize(N + 1);
  for (int i = 1; i <= N; i++)
  {
    cin >> heap[i];
    upAdjust(i); // 关键：每插入一个就向上调整
  }

  // 2. 建立值到下标的映射，方便 O(1) 查询
  for (int i = 1; i <= N; i++)
  {
    pos[heap[i]] = i;
  }

  cin.ignore(); // 吸收换行符

  // 3. 处理查询命题
  while (M--)
  {
    string line;
    getline(cin, line);
    stringstream ss(line);

    int x, y;
    string temp;

    ss >> x >> temp; // 读入第一个数和其后的单词

    if (temp == "and")
    { // x and y are siblings
      ss >> y >> temp >> temp;
      // 兄弟逻辑：父节点下标相同 且 x, y 都在堆中
      if (pos.count(x) && pos.count(y))
      {
        printResult(pos[x] / 2 == pos[y] / 2 && pos[x] != pos[y]);
      }
      else
        printResult(false);
    }
    else
    {             // x is ...
      ss >> temp; // 读入 'the' 或 'a'
      ss >> temp; // 读入 'root', 'parent', 'child'

      if (temp == "root")
      { // x is the root
        printResult(pos[x] == 1);
      }
      else if (temp == "parent")
      { // x is the parent of y
        ss >> temp >> y;
        if (pos.count(x) && pos.count(y))
        {
          printResult(pos[y] / 2 == pos[x]);
        }
        else
          printResult(false);
      }
      else if (temp == "child")
      { // x is a child of y
        ss >> temp >> y;
        if (pos.count(x) && pos.count(y))
        {
          printResult(pos[x] / 2 == pos[y]);
        }
        else
          printResult(false);
      }
    }
  }

  return 0;
}