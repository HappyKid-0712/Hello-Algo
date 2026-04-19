#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int N;
  cin >> N;
  int best_start = 2, max_len = 0;
  for (int i = 2; i <= sqrt(N) + 1; i++)
  {
    int temp_product = 1;
    int j = i;
    while (true)
    {
      temp_product *= j;
      if (N % temp_product == 0)
      {
        ll current_len = j - i + 1;
        if (current_len > max_len)
        {
          max_len = current_len;
          best_start = i;
        }
      }
      else
      {
        break;
      }
      j++;
    }
  }
  if (max_len == 0)
  {
    cout << 1 << endl
         << N << endl;
  }
  else
  {
    cout << max_len << endl;
    for (int i = 0; i < max_len; i++)
    {
      cout << best_start + i;
      if (i != max_len - 1)
      {
        cout << "*";
      }
    }
    cout << endl;
  }
  return 0;
}