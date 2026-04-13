#include <bits/stdc++.h>
using namespace std;
struct NODE
{
  int data;
  int next;
  NODE(int a, int b) : data(a), next(b) {};
};

int main()
{
  vector<NODE> list(10, NODE(1, 0));
  list[0] = NODE(10, 2);
  list[2] = NODE(4, 3);
  list[3] = NODE(2, -1);
  list[7] = NODE(17, -1);

  int index = 0;
  while (index != -1)
  {
    if (list[index].data == 10)
    {
      list[7].next = list[index].next;
      list[index].next = 7;
    }
    index = list[index].next;
  }

  index = 0;
  while (index != -1)
  {
    if (list[list[index].next].data == 4)
    {
      int nextIndex = list[index].next;
      list[index].next = list[nextIndex].next;
    }
    index = list[index].next;
  }

  index = 0;
  while (index != -1)
  {
    cout << list[index].data << ' ';
    index = list[index].next;
  }

  return 0;
}