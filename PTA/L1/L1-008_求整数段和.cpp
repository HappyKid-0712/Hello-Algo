#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int start, end;
  cin >> start >> end;
  ll sum = 0;
  int count = 0;
  for (int i = start; i <= end; i++)
  {

    cout << setw(5) << i;
    sum += i;
    count++;
    if (count % 5 == 0)
    {
      cout << endl;
    }
  }
  if (count % 5 != 0)
  {
    cout << endl;
  }
  cout << "Sum = " << sum << endl;
  return 0;
}