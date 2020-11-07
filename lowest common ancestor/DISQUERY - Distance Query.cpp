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

const int N = 1e5 + 5;
vector <P> Graph[N];
int level[N];
int lca[N][18];
int max_e[N][18], min_e[N][18];
vb vis(N);
int n;

void dfs(int src, int par, int l, int dis) {
	vis[src] = true;
	level[src] = l;

	if (dis != -1) {
		max_e[src][0] = dis;
		min_e[src][0] = dis;
	}
	lca[src][0] = par;

	REP(i, 1, 18) {
		if (lca[src][i - 1] != -1) {
			int p = lca[src][i - 1];

			lca[src][i] = lca[p][i - 1];

			max_e[src][i] = max(max_e[src][i - 1], max_e[p][i - 1]);
			min_e[src][i] = min(min_e[src][i - 1], min_e[p][i - 1]);
		}
	}

	for (auto x : Graph[src]) {
		int to = x.F;
		int w = x.S;
		if (!vis[to]) {
			dfs(to, src, l + 1, w);
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

	REV(i, 17, 0) {
		if (lca[a][i] != -1 && lca[a][i] != lca[b][i]) {
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}

P calc(int a, int LCA) {

	int d = level[a] - level[LCA];

	P ans;
	ans.F = -1, ans.S = (int)1e18;

	while (d > 0) {
		int i = log2(d);

		ans.F = max(ans.F, max_e[a][i]);
		ans.S = min(ans.S, min_e[a][i]);

		a = lca[a][i];
		d -= (1 << i);
	}
	return ans;
}

void solve() {

	cin >> n;

	fill(all(vis), false);
	fill(level, level + N, 0);
	REP(i, 0, n) {
		Graph[i].clear();
		REP(j, 0, 18) {
			lca[i][j] = -1;
			max_e[i][j] = -1;
			min_e[i][j] = (int)1e18;
		}
	}

	REP(i, 1, n - 1) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}

	dfs(1, -1, 0, -1);

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		int LCA = find_lca(a, b);

		P ans = calc(a, LCA);
		P temp = calc(b, LCA);

		ans.F = max(ans.F, temp.F);
		ans.S = min(ans.S, temp.S);

		cout << ans.S << " " << ans.F << endl;
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