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

struct FenwickTree2d
{
    vector<vector<int>> ft;
    int xs, ys;

    FenwickTree2d(int x, int y)
    {
        this->xs = x + 1;
        this->ys = y + 1;
        ft.assign(x + 1, vector<int>(y + 1, 0));
    }

    ll query(int x, int y)
    {
        ll sum = 0;
        for (int i = x; i > 0; i -= -i & i)
            for (int j = y; j > 0; j -= -j & j)
                sum += ft[i][j];
        return sum;
    }

    void update(ll x, ll y, ll val)
    {
        for (int i = x; i < xs; i += -i & i)
            for (int j = y; j < ys; j += -j & j)
                ft[i][j] += val;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    FenwickTree2d ft(n, n);
    vector<string> s(n);
    rep(i, 0, n)
    {
        cin >> s[i];
        rep(j, 0, n)
        {
            if (s[i][j] == '*')
            {
                ft.update(i + 1, j + 1, 1);
            }
        }
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            if (s[x - 1][y - 1] == '*')
            {
                ft.update(x, y, -1);
                s[x - 1][y - 1] = '.';
            }
            else
            {
                ft.update(x, y, 1);
                s[x - 1][y - 1] = '*';
            }
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << ft.query(x2, y2) - ft.query(x1 - 1, y2) - ft.query(x2, y1 - 1) + ft.query(x1 - 1, y1 - 1) << endl;
        }
    }
    return 0;
}
