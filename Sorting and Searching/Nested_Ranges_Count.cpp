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

class range
{
public:
    int l, r, idx;
    range(int l, int r, int idx)
    {
        this->l = l;
        this->r = r;
        this->idx = idx;
    }
    bool operator<(const range &other) const
    {
        return l == other.l ? r > other.r : l < other.l;
    }
};

struct FenwickTree
{
    vector<int> ft;
    int n;

    FenwickTree(int n)
    {
        this->n = n + 1;
        ft.assign(n + 1, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size() + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            ft[i] += a[i - 1];
            int p = i + (i & (-i));
            if (p <= n)
                ft[p] += ft[i];
        }
    }

    ll query(int x)
    {
        ll ans = 0;
        while (x > 0)
        {
            ans += ft[x];
            x -= (x & (-x));
        }
        return ans;
    }

    void update(ll x, ll y)
    {
        while (x < n)
        {
            ft[x] += y;
            x += (x & (-x));
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<range> a;
    map<int, int> mp;
    int cnt = 0;
    set<int> b;
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        b.insert(y);
        a.push_back(range(x, y, i));
    }
    for (auto i : b)
    {
        mp[i] = ++cnt;
    }

    sort(a.begin(), a.end());
    vector<int> contains(n, 0);
    vector<int> contained(n, 0);

    FenwickTree ft(mp.size() + 10);
    ft.update(mp[a[n - 1].r], 1);
    for (int i = n - 2; i >= 0; i--)
    {
        contains[a[i].idx] += ft.query(mp[a[i].r]);
        ft.update(mp[a[i].r], 1);
    }
    rep(i, 0, n)
    {
        cout << contains[i] << " ";
    }

    FenwickTree ft2(mp.size() + 10);
    ft2.update(1, 1);
    ft2.update(mp[a[0].r] + 1, -1);
    for (int i = 1; i < n; i++)
    {
        contained[a[i].idx] += ft2.query(mp[a[i].r]);
        ft2.update(1, 1);
        ft2.update(mp[a[i].r] + 1, -1);
    }
    cout << "\n";
    rep(i, 0, n)
    {
        cout << contained[i] << " ";
    }
    cout << "\n";
    return 0;
}
