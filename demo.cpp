#include <bits/stdc++.h>
using namespace std;
float ming;
long long score, n, l;
map<int, int> mp;
vector<int> vt;
int main()
{
    cin >> score >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l;
        vt.push_back(l);
    }
    sort(vt.begin(), vt.end());
    reverse(vt.begin(), vt.end());

    for (int i = 0; i < vt.size(); i++)
    {
        if (!mp.count(vt[i]))
        {
            mp[vt[i]] = i + 1;
        }
    }
    ming = mp[score] * 10;

    if (ming <= 1 * n)
    {
        cout << 'A';
    }
    else if (ming <= 3 * n)
    {
        cout << 'B';
    }
    else if (ming <= 6 * n)
    {
        cout << 'C';
    }
    else if (ming <= 8 * n)
    {
        cout << 'D';
    }
    else
    {
        cout << 'E';
    }
    return 0;
}