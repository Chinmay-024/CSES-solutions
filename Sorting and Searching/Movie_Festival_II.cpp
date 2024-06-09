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

multiset<ll> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;

    vii a(n);
    rep(i, 0, n)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    rep(i, 0, k) s.insert(0);
    ll ans = 0;
    rep(i, 0, n)
    {
        auto it = s.upper_bound(a[i].second); // for movie finished at or before start time
        if (it != s.begin())
        {
            s.erase(prev(it));
            s.insert(a[i].first);
            ans++;
        }
    }
    cout << ans;
    return 0;
}