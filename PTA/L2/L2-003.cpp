#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MAXN = 1e5 + 5;
struct MoonCake
{
  double total_price;
  double amount;
  double unit_price;
};
bool cmp(MoonCake A, MoonCake B)
{
  return A.unit_price > B.unit_price;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int N;
  double market_needed;
  cin >> N >> market_needed;
  vector<MoonCake> vec(N);
  for (int i = 0; i < N; i++)
  {
    cin >> vec[i].amount;
  }
  for (int i = 0; i < N; i++)
  {
    cin >> vec[i].total_price;
    vec[i].unit_price = vec[i].total_price / vec[i].amount;
  }
  sort(vec.begin(), vec.end(), cmp);
  double res = 0;
  for (auto it : vec)
  {
    // 根据排序来将market_needed减完
    if (it.amount <= market_needed)
    {
      market_needed -= it.amount;
      res += it.total_price;
    }
    else
    {
      res += it.total_price / (it.amount / market_needed);
      market_needed = 0;
    }
    if (market_needed < 0)
    {
      break;
    }
  }
  cout << fixed << setprecision(2) << res;
  return 0;
}