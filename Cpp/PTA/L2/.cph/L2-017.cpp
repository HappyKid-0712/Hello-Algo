#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
  int n;
  if (!(cin >> n))
    return 0;

  vector<int> vec(n);
  long long allSum = 0; // 使用 long long 防止求和溢出
  for (int i = 0; i < n; i++)
  {
    cin >> vec[i];
    allSum += vec[i];
  }

  sort(vec.begin(), vec.end());

  int n2 = n / 2;  // 内向组（较小的那一半）人数
  int n1 = n - n2; // 外向组（较大的那一半）人数

  long long smallSum = 0;
  // 只累加前 n/2 个最小的数
  for (int i = 0; i < n2; i++)
  {
    smallSum += vec[i];
  }

  long long bigSum = allSum - smallSum;
  long long diff = bigSum - smallSum;

  cout << "Outgoing #: " << n1 << endl;
  cout << "Introverted #: " << n2 << endl;
  cout << "Diff = " << diff << endl;

  return 0;
}