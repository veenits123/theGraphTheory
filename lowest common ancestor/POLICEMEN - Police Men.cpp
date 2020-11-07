#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e4 + 5;
vi Graph[N];
int level[N];
int par[N][17];
int n;

void dfs(int src, int p, int l) {
	level[src] = l;
	par[src][0] = p;

	REP(i, 1, 16) {
		if (par[src][i - 1] != -1) {
			par[src][i] = par[par[src][i - 1]][i - 1];
		}
	}

	for (int to : Graph[src]) {
		if (to != p) {
			dfs(to, src, l + 1);
		}
	}
}

int lca(int a, int b) {
	if (level[a] > level[b])
		swap(a, b);
	int d = level[b] - level[a];
	while (d > 0) {
		int i = log2(d);
		b = par[b][i];
		d -= (1 << i);
	}
	if (a == b)
		return a;
	REV(i, 16, 0) {
		if (par[a][i] != -1 && par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

void solve() {

	REP(i, 0, N - 1) {
		REP(j, 0, 16) {
			par[i][j] = -1;
		}
		Graph[i].clear();
		level[i] = 0;
	}
	cin>>n;

	REP(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}

	dfs(1, -1, 0);

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		int lc = lca(a, b);
		if (level[a] >= level[b]) {
			cout << "YES" << " " << lc << endl;
		}
		else
			cout << "NO" << endl;
	}

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}