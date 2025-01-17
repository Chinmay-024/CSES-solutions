#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
            cin >>
        a[i];
    map<ll, ll> mp;
    ll idx = 0;
    ll ans = 1;
    mp[a[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = i;
        }
        else
        {
            idx = max(idx, mp[a[i]] + 1);
            mp[a[i]] = i;
        }
        ans = max(ans, i - idx + 1);
    }
    cout
        << ans;
    return 0;
}