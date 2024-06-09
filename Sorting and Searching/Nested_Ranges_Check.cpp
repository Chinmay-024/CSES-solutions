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

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<range> a;
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(range(x, y, i));
    }
    sort(a.begin(), a.end());
    vector<bool> contains(n, false);
    vector<bool> contained(n, false);

    int maxR = a[0].r;
    rep(i, 1, n)
    {
        if (a[i].r <= maxR)
        {
            contained[a[i].idx] = true;
        }
        maxR = max(maxR, a[i].r);
    }

    int minR = a[n - 1].r;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i].r >= minR)
        {
            contains[a[i].idx] = true;
        }
        minR = min(minR, a[i].r);
    }
    rep(i, 0, n)
    {
        cout << (contains[i] ? 1 : 0) << " ";
    }
    cout << "\n";
    rep(i, 0, n)
    {
        cout << (contained[i] ? 1 : 0) << " ";
    }
    cout << "\n";
    return 0;
}