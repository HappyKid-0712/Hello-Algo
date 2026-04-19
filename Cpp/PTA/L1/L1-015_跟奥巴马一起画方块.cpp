#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int len;
  char letter;
  cin >> len >> letter;

  for (int i = 0; i < (len + 2 / 2) / 2; i++)
  {
    for (int j = 0; j < len; j++)
    {
      cout << letter;
    }
    cout << endl;
  }
  return 0;
}