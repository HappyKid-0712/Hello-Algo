#include <bits/stdc++.h>
using namespace std;
string n;
int k;
int cnt = 0;
stack<char> st;
int main()
{
    cin >> n >> k;
    for (auto it : n)
    {
        while (!st.empty() && it > st.top() && cnt < k) // delete,cnt<k
        {
            st.pop();
            cnt++;
        }
        st.push(it);
    }

    while (cnt < k && !st.empty())
    {
        st.pop();
        ++cnt;
    }

    string res = "";
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}