#include <bits/stdc++.h>
using namespace std;

int main()
{
  int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
  char checkCode[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

  int N;
  cin >> N;
  bool allPassed = true;

  while (N--)
  {
    string str;
    cin >> str;
    int sum = 0;
    bool hasInvalidChar = false;

    // 检查前17位是否全为数字，并计算加权和
    for (int i = 0; i < 17; i++)
    {
      if (!isdigit(str[i]))
      { // 如果前17位出现了非数字字符（如'X'）
        hasInvalidChar = true;
        break;
      }
      sum += (str[i] - '0') * weight[i]; // 权重对应位置 i
    }

    if (hasInvalidChar)
    {
      allPassed = false;
      cout << str << endl;
    }
    else
    {
      int Z = sum % 11;
      if (checkCode[Z] != str[17])
      { // 检查计算出的校验码是否等于第18位
        allPassed = false;
        cout << str << endl;
      }
    }
  }

  if (allPassed)
  {
    cout << "All passed" << endl;
  }

  return 0;
}