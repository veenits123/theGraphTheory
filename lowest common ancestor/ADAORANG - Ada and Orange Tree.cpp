#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <bitset>
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

const int N = 45e4 + 5;
vi Graph[N];
int level[N];
int lca[N][20];
int n, q, root;
int color[N];
bitset <260> shades[N];

void dfs(int src, int par, int l) {
	level[src] = l + 1;
	lca[src][0] = par;

	shades[src][color[src]] = 1;

	REP(i, 1, 19) {
		if (lca[src][i - 1] != -1) {
			lca[src][i] = lca[lca[src][i - 1]][i - 1];
		}
	}
	for (auto to : Graph[src]) {
		if (to != par) {
			dfs(to, src, l + 1);
			shades[src] |= shades[to];
		}
	}
}

int find_lca(int a, int b) {
	if (level[a] > level[b])
		swap(a, b);
	int d = level[b] - level[a];
	while (d > 0) {
		int i = log2(d);
		b = lca[b][i];
		d -= (1 << i);
	}
	if (a == b)
		return a;
	REV(i, 19, 0) {
		if (lca[a][i] != -1 && lca[a][i] != lca[b][i]) {
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}

void solve() {

	cin >> n >> q >> root;
	REP(i, 0, n - 1)
	cin >> color[i];

	REP(i, 0, n) {
		REP(j, 0, 19) {
			lca[i][j] = -1;
		}
		level[i] = 0;
		Graph[i].clear();
		shades[i].reset();
	}
	REP(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}

	dfs(root, -1, 0);

	while (q--) {
		int a, b; cin >> a >> b;
		int LCA = find_lca(a, b);
		cout << (int)shades[LCA].count() << endl;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}