#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
  // 优化 I/O 速度，在限时算法比赛中是个好习惯
  ios::sync_with_stdio(false);
  cin.tie(0);

  int y, n;
  if (!(cin >> y >> n))
    return 0;

  // i 代表经过的年数，也就是遇到的岁数 x
  for (int i = 0;; ++i)
  {
    int current_year = y + i;
    string s = to_string(current_year);

    // 核心突破口：不足 4 位，在前面补齐 '0'
    if (s.length() < 4)
    {
      s = string(4 - s.length(), '0') + s;
    }

    // 将字符串放入哈希集合中，自动完成去重
    unordered_set<char> digits(s.begin(), s.end());

    // 如果集合的大小等于目标个数 n，说明找到了符合要求的年份
    if (digits.size() == n)
    {
      // 直接输出岁数和格式化好的年份字符串
      cout << i << " " << s << "\n";
      break;
    }
  }

  return 0;
}