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
vector <P> Graph[N];
int lca[N][18];
int dis[N];
int level[N];
int n;

void dfs(int src, int par, int l) {
	level[src] = l;
	lca[src][0] = par;

	REP(i, 1, 17) {
		if (lca[src][i - 1] != -1) {
			int p = lca[src][i - 1];
			lca[src][i] = lca[p][i - 1];
		}
	}
	for (auto x : Graph[src]) {
		int to = x.F;
		int w = x.S;
		if (to != par) {
			dis[to] = dis[src] + w;
			dfs(to, src, l + 1);
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

int distance(int a, int b) {
	int LCA = find_lca(a, b);
	int ans = dis[a] + dis[b] - 2 * dis[LCA];
	return ans;
}

int kth_node(int a, int b, int k) {
	int LCA = find_lca(a, b);
	if (LCA == a) {
		int d = level[b] - level[a] + 1;
		k = d - k + 1;
		swap(a, b);//LCA-b part;
	}
	//k must be less than b so just find k-th parent from a by lca;
	else if (LCA == b); //a-LCA part;
	else {
		//k lies in LCA-b part;
		if (k > level[a] - level[LCA] + 1) {
			int d = level[a] + level[b] - 2 * level[LCA] + 1;
			k = d - k + 1;
			swap(a, b);
		}
	}
	k--;
	while (k > 0) {
		int i = log2(k);
		a = lca[a][i];
		k -= (1 << i);
	}
	return a;
}

void solve() {

	cin >> n;
	REP(i, 0, n) {
		Graph[i].clear();
		REP(j, 0, 17) {
			lca[i][j] = -1;
		}
		dis[i] = 0;
		level[i] = 0;
	}
	REP(i, 1, n - 1) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	dfs(1, -1, 0);

	while (true) {
		string s; cin >> s;
		if (s == "DONE")
			break ;
		else if (s == "DIST") {
			int a, b; cin >> a >> b;

			cout << distance(a, b) << endl;
		}
		else {
			int a, b, k; cin >> a >> b >> k;

			cout << kth_node(a, b, k) << endl;
		}
	}
	cout << endl;

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

	int t; cin >> t; while (t--) {
		solve();
	}

	return 0;
}