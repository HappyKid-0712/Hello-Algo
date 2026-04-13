#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 10
struct Sqlist
{
  int data[MAXSIZE];
  int lenth;
};

void InitSqlist(Sqlist &L)
{
  L.lenth = 0;
}

int main()
{
  Sqlist L;
  InitSqlist(L);

  for (int i = 0; i < MAXSIZE; i++)
  {
    cout << L.data[i] << endl;
  }
  return 0;
}