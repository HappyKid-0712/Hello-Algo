#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
int main()
{
  int N;
  cin >> N;
  while (N--)
  {
    int startTime[1001] = {0};
    bool vis[1001] = {false};
    int cnt = 0;
    double total_time = 0;

    int id, hh, mm;
    char key;
    while (scanf("%d %c %d:%d", &id, &key, &hh, &mm) && id != 0)
    {
      int tiemInMinutes = hh * 60 + mm;
      if (key == 'S')
      {
        startTime[id] = tiemInMinutes;
        vis[id] = true;
      }
      else if (key == 'E')
      {
        if (vis[id])
        {
          total_time += (tiemInMinutes - startTime[id]);
          cnt++;
          vis[id] = false;
        }
      }
    }
    if (cnt == 0)
    {
      cout << "0 0" << endl;
    }
    else
      cout << cnt << ' ' << (int)round(total_time / cnt) << endl;
  }

  return 0;
}