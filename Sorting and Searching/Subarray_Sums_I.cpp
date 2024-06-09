#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define vi vector<int>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, y;
    cin >> n >> y;
    ll sum = 0;
    ll ans = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        sum += x;
        ans += mp[sum - y];
        mp[sum]++;
    }
    cout << ans;
    return 0;
}