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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    ll maxi = 0;
    ll sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    rep(i, 0, n)
    {
        maxi = max(maxi, a[i]);
        sum += a[i];
    }
    sum -= a[n - 1];
    if (sum <= maxi)
        cout << 2 * maxi;
    else
        cout << sum + maxi;

    return 0;
}