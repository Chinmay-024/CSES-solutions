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
    int n;
    cin >> n;
    vi a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int l = a.size();
        int low = 0, high = l;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (a[mid] > x)
                high = mid;
            else
                low = mid + 1;
        }
        if (low == l)
            a.push_back(x);
        else
            a[low] = x;
    }
    cout << a.size();
    return 0;
}