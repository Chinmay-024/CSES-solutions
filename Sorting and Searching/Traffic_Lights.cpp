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
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x, n;
    cin >> x >> n;
    set<ll> p{0, x};
    multiset<ll> s;

    s.insert(x);

    for (int i = 0; i < n; i++)
    {
        int pos;
        cin >> pos;
        auto it = p.upper_bound(pos);
        auto it2 = it;
        --it2;
        s.erase(s.find(*it - *it2));
        s.insert(pos - *it2);
        s.insert(*it - pos);
        p.insert(pos);
        cout << *(--s.end()) << " ";
    }

    return 0;
}