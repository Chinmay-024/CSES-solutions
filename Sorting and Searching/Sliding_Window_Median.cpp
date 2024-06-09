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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    oset<pii> s;
    vi a(n);
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[i] = x;
        s.insert({x, i});
        if (i >= k - 1)
        {
            auto it = s.find_by_order((k - 1) / 2);
            cout << it->ff << " ";
            s.erase(s.lower_bound({a[i - k + 1], i - k + 1}));
        }
    }
    return 0;
}