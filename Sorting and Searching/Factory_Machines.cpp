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

bool isPossible(ll x, vi &k, ll t)
{
    ll ans = 0;
    for (ll i = 0; i < k.size(); i++)
    {
        ans += x / k[i];
        if (ans >= t)
            break;
    }
    return ans >= t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t;
    cin >> n >> t;
    vi k(n);
    ll maxi = 0;
    rep(i, 0, n)
    {
        cin >> k[i];
        maxi = max(maxi, k[i]);
    }
    ll l = 0;
    ll h = 1e18;
    ll ans = 1e18;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        bool check = isPossible(mid, k, t);
        if (check)
        {
            ans = min(ans, mid);
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}