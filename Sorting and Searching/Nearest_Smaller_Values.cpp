#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    stack<pii> s;
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        while (!s.empty() && s.top().first >= x)
        {
            s.pop();
        }

        if (s.empty())
            cout << 0 << " ";
        else
            cout << s.top().second + 1 << " ";
        s.push({x, i});
    }
    return 0;
}