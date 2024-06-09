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
    int n, x;
    cin >> n >> x;
    vii a(n);
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    rep(i, 0, n)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            if (a[i].ff + a[l].ff + a[r].ff == x)
            {
                cout << a[i].ss + 1 << " " << a[l].ss + 1 << " " << a[r].ss + 1 << endl;
                return 0;
            }
            else if (a[i].ff + a[l].ff + a[r].ff < x)
                l++;
            else
                r--;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}