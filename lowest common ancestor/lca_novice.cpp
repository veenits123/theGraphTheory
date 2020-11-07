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

const int N = 1e3 + 100;
vi Graph[N];
int par[N];
int level[N];
vb vis(N);
int n;

void dfs(int root, int p, int l) {
	vis[root] = true;
	l++;
	for (auto to : Graph[root]) {
		if (to == p)
			continue;
		if (!vis[to]) {
			par[to] = root;
			level[to] = l;
			dfs(to, root, l);
		}
	}
}

int find_lca(int a, int b) {
	if (level[a] > level[b])
		swap(level[a], level[b]);

	int diff = level[b] - level[a];

	while (diff > 0) {
		b = par[b];
		diff--;
	}
	if (a == b)
		return a;

	while (par[a] != par[b]) {
		a = par[a];
		b = par[b];
	}
	return par[a];
}

void solve() {

	fill(par, par + N, -1);
	fill(level, level + N, 0);
	fill(all(vis), false);
	REP(i, 0, N)
	Graph[i].clear();

	cin >> n;
	REP(i, 1, n) {
		int x; cin >> x;
		while (x--) {
			int child; cin >> child;
			Graph[i].pb(child);
			Graph[child].pb(i);
		}
	}
	dfs(1, -1, 0);

	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		cout << find_lca(u, v) << endl;
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

	int t, tc; cin >> t; tc = t; while (t--) {
		cout << "Case " << tc - t << ":" << endl;
		solve();
	}

	return 0;
}