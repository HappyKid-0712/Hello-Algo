#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int A[105][105], B[105][105], C[105][105];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int Ra, Ca, Rb, Cb;

  cin >> Ra >> Ca;
  for (int i = 0; i < Ra; i++)
  {
    for (int j = 0; j < Ca; j++)
    {
      cin >> A[i][j];
    }
  }

  cin >> Rb >> Cb;
  for (int i = 0; i < Rb; i++)
  {
    for (int j = 0; j < Cb; j++)
    {
      cin >> B[i][j];
    }
  }

  if (Ca != Rb)
  {
    cout << "Error: " << Ca << " != " << Rb;
    return 0;
  }
  for (int i = 0; i < Ra; i++)
  {
    for (int j = 0; j < Cb; j++)
    {
      int res = 0;
      for (int k = 0; k < Rb; k++)
      {
        res += A[i][k] * B[k][j];
      }
      C[i][j] = res;
    }
  }
  cout << Ra << ' ' << Cb << endl;
  for (int i = 0; i < Ra; i++)
  {
    for (int j = 0; j < Cb; j++)
    {
      if (j > 0)
      {
        cout << ' ';
      }
      cout << C[i][j];
    }
    cout << endl;
  }
  return 0;
}