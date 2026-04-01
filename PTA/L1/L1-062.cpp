#include <bits/stdc++.h>
using namespace std;
int T;
int numIn;

int func(int &x)
{
  int ans = 0;
  for (int i = 0; i < 3; i++)
  {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

bool solve(int num)
{
  int frontSum = func(num);
  int endSum = func(num);
  return frontSum == endSum;
}

int main()
{
  cin >> T;
  while (T--)
  {
    cin >> numIn;
    if (solve(numIn))
    {
      cout << "You are lucky!" << endl;
    }
    else
    {
      cout << "Wish you good luck." << endl;
    }
  }

  return 0;
}