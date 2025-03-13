#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> PLI;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e5 + 50;
#define fo(i, n) for (int i = 1; i <= n; ++i)
#define rep(i, k, n) for (int i = k; i <= n; ++i)
#define inf 0x3f3f3f3f

int match[N];
int va[N], vb[N];
int la[N], lb[N];
int d[N];
int w[N][N];
int n, m;
bool dfs(int x)
{
	va[x] = 1;
	fo(y, n)
	{
		if (!vb[y])
		{
			if (la[x] + la[y] == w[x][y])
			{
				vb[y] = 1;
				if (!match[y] || dfs(match[y]))
				{
					match[y] = x;
					return true;
				}
			}
		}
		else
		{
			d[y]=min(d[y],la[x]+lb[y]-w[x][y]);
		}
	}
	return false;
}
int KM()
{
	fo(i, n) la[i] = -inf;
	fo(i, n)
		fo(j, n)
			la[i] = max(la[i], w[i][j]);
	fo(i, n) lb[i] = 0;

	fo(i, n) //
	{
		while (true)
		{
			fill(va + 1, va + n + 1, 0);
			fill(vb + 1, vb + n + 1, 0);
			fill(d + 1, d + n + 1, inf);
			if (dfs(i))
				break;

			//
			int delta=inf;
			fo(j,n)
			{
				if(!vb[j])delta=min(delta,d[j]);
			}
			for (int j = 1; j <= n; j++)
			{
				if(va[j])la[j]-=delta;
				if(vb[j])lb[j]+=delta;
			} 
		}
	}
	int res=0;
	fo(i,n)
	{
		res+=w[match[i]][i];
	}
	cout<<res<<'\n';
	
}
void solve()
{
	
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
