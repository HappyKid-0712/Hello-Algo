#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int max_a, max_b;
  cin >> max_a >> max_b;
  int N;
  cin >> N;
  int a_gus, a_do, b_gus, b_do;
  int ah = 0, bh = 0;
  while (N--)
  {
    cin >> a_gus >> a_do >> b_gus >> b_do;
    if (a_do == a_gus + b_gus && b_do == a_gus + b_gus)
    {
      continue;
    }
    else if (a_do == a_gus + b_gus)
    {
      max_a--;
      ah++;
    }
    else if (b_do == a_gus + b_gus)
    {
      max_b--;
      bh++;
    }
    // 谁先到
    if (max_a < 0)
    {
      cout << "A" << endl
           << bh;
      return 0;
    }
    if (max_b < 0)
    {
      cout << "B" << endl
           << ah;
      return 0;
    }
  }

  return 0;
}