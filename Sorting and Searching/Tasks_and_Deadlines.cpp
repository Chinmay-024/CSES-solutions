#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define ff first
#define ss second

const ll M = 2e6 + 20;
vector<ll> fact(M, 1);
const ll N = 1e5 + 7;
const ll MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vii a;
    rep(i, 0, n)
    {
        ll x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    ll t = 0;
    ll ans = 0;
    rep(i, 0, n)
    {
        t += a[i].ff;
        ans += (a[i].ss - t);
    }
    cout << ans;
    return 0;
}