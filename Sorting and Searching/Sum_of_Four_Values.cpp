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

unordered_map<ll, vector<pii>> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vi a(n, 0);
    rep(i, 0, n)
    {
        cin >> a[i];
        rep(j, 0, i)
        {
            ll sum = a[i] + a[j];
            if (mp.find(x - sum) != mp.end())
            {
                for (auto p : mp[x - sum])
                {
                    if (p.ff == i || p.ss == i || p.ff == j || p.ss == j)
                        continue;
                    cout << p.ff + 1 << " " << p.ss + 1 << " " << i + 1 << " " << j + 1;
                    return 0;
                }
            }
            else
            {
                mp[sum].push_back({j, i});
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}