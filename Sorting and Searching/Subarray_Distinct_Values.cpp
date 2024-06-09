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
    ll n, x;
    cin >> n >> x;
    map<ll, ll> mp;
    ll l = 0, r = 0;
    ll distinct = 0, ans = 0;
    vi a(n, 0);
    while (r < n)
    {
        cin >> a[r];
        if (mp[a[r]] == 0)
        {
            distinct++;
        }
        mp[a[r]]++;

        while (distinct > x && l <= r)
        {
            mp[a[l]]--;
            if (mp[a[l]] == 0)
                distinct--;
            l++;
        }
        ans += r - l + 1;
        r++;
    }
    cout << ans << "\n";
    return 0;
}