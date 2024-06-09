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

ll sLow = 0, sHigh = 0, k;
multiset<ll> low, high;

void insert(ll val)
{
    ll x = *(low.rbegin());
    if (val > x)
    {
        high.insert(val);
        sHigh += val;
        if (high.size() > k / 2)
        {
            sHigh -= *(high.begin());
            sLow += *(high.begin());
            low.insert(*(high.begin()));
            high.erase(high.begin());
        }
    }
    else
    {
        low.insert(val);
        sLow += val;
        if (low.size() > (k + 1) / 2)
        {
            sLow -= *(low.rbegin());
            sHigh += *(low.rbegin());
            high.insert(*(low.rbegin()));
            low.erase(low.find(*(low.rbegin())));
        }
    }
}

void erase(ll val)
{
    if (high.find(val) != high.end())
    {
        high.erase(high.find(val));
        sHigh -= val;
    }
    else
    {
        low.erase(low.find(val));
        sLow -= val;
    }
    if (low.empty())
    {
        low.insert(*high.begin());
        sLow += *high.begin();
        sHigh -= *high.begin();
        high.erase(high.begin());
    }
}

ll med() { return (k % 2 == 0) ? 0 : (*low.rbegin()); }

void print()
{
    cout << sHigh - sLow + med() << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n >> k;
    vi a(n);
    cin >> a[0];
    sLow += a[0];
    low.insert(a[0]);
    rep(i, 1, k)
    {
        ll x;
        cin >> x;
        a[i] = x;
        insert(x);
    }
    print();
    rep(i, k, n)
    {
        ll x;
        cin >> x;
        if (k == 1)
        {
            insert(x);
            erase(a[i - k]);
        }
        else
        
        {
            erase(a[i - k]);
            insert(x);
        }
        a[i] = x;
        print();
    }
    return 0;
}