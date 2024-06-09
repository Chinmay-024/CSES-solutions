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
    ll n, a, b;
    cin >> n >> a >> b;
    vi prefix(n + 1, 0);
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        prefix[i + 1] = prefix[i] + x;
    }
    ll ans = -1e17;
    rep(i, a, n + 1)
    {
        if (i > b)
        {
            s.erase(s.find(prefix[i - b - 1]));
        }
        s.insert(prefix[i - a]);
        ans = max(ans, prefix[i] - *s.begin());
    }
    cout << ans;
    return 0;
}