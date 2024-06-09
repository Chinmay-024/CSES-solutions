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
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (int j = 0; j < s.size(); j++)
        {
            v[i] += (s[j] == '1') * (1 << j);
        }
    }
    int ans = 32;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = min(ans, (int)__builtin_popcount(v[i] ^ v[j]));
        }
    }
    cout << ans;
    return 0;
}