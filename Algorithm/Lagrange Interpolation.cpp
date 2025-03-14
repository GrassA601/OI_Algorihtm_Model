#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define int long long
typedef pair<int, int> pii;
const int mod = 998244353;

#define fo(i, n) for (int i = 1; i <= n; ++i)
#define rep(i, k, n) for (int i = k; i <= n; ++i)
#define inf 0x3f3f3f3f
const int N = 2e5 + 50;

// lagrange Interpolation

typedef pair<int, int> pii;
vector<pii> po;
int n, k;
int lk()
{
    int res = 1;
    fo(i, n)
    {
        res = (res * (k - po[i].first) + mod) % mod;
    }
    return res;
}
inline int fpow(int x, int exp)
{
    int res = 1;
    for (; exp; exp >>= 1, x = (x * x) % mod)
    {
        if (exp & 1)
            res = res * x % mod;
    }
    return res;
}

void solve()
{
    cin >> n >> k;
    po.resize(n + 1);
    fo(i, n)
    {
        int x, y;
        cin >> x >> y;
        po[i] = make_pair(x, y);
    }
    int a = lk();
    int b = 0;
    fo(i, n)
    {
        int y = po[i].second;
        int inv = fpow((k - po[i].first +mod) % mod, mod - 2);
        
        int den = 1;

        fo(j, n)
        {
            if (i != j)
                den = (den * (po[i].first - po[j].first + mod) % mod) % mod;//
        }
        den = fpow(den, mod - 2);
        b = (b + (y * inv %mod * den %mod + mod) % mod) % mod;
        //module after each multi
    }
    cout << (a * b) % mod;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
