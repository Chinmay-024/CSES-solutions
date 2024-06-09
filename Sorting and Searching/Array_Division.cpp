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

bool isPossible(vi &a, ll x, ll k)
{
    ll sum = 0, distinct = 1;
    for (auto i : a)
    {
        if (i > x)
            return false;
        if (sum + i <= x)
            sum += i;
        else
        {
            sum = i;
            distinct++;
        }
        if (distinct > k)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vi a(n, 0);
    ll sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll l = 0, h = sum, ans = sum;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        if (isPossible(a, mid, k))
        {
            ans = min(ans, mid);
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}