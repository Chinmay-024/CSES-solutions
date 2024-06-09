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

string s;
int a[4][4];
unordered_map<char, int> mp;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = s.size();
    mp['A'] = 0;
    mp['T'] = 1;
    mp['G'] = 2;
    mp['C'] = 3;
    char ch[] = {'A', 'T', 'G', 'C'};
    ll count = 0;
    string ans;
    vi has(4, 0);
    rep(i, 0, n)
    {
        int x = mp[s[i]];
        if (!has[x])
        {
            count++;
            has[x] = 1;
            if (count == 4)
            {
                fill(has.begin(), has.end(), 0);
                ans += s[i];
                count = 0;
            }
        }
    }
    cout << ans;
    rep(i, 0, 4)
    {
        if (!has[i])
        {
            cout << ch[i];
            break;
        }
    }

    return 0;
}