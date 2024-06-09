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
    int t;
    cin >> t;
    map<ll, ll> mp;
    mp[0] = 1;
    ll sum = 0;
    rep(i, 0, t)
    {
        int x;
        cin >> x;
        sum += x;
        mp[(sum % t + t) % t] += 1;
    }
    ll ans = 0;
    for (auto x : mp)
    {
        ans += (x.ss * (x.ss - 1)) / 2;
    }
    cout << ans;
    return 0;
}