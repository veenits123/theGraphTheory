#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cstring>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

//#define int long long int
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

const int N = 5e4 + 5;
vector <P> Graph[N];
int lca[N][17];
int dis[N][17];
int dis2[N];
int level[N];
int n;

void dfs(int src, int par, int l, int d) {
	level[src] = l;
	lca[src][0] = par;

	// if (d != -1) {
	// 	dis[src][0] = d;
	// }

	REP(i, 1, 16) {
		if (lca[src][i - 1] != -1) {
			int p = lca[src][i - 1];
			lca[src][i] = lca[p][i - 1];

			//dis[src][i] = dis[src][i - 1] + dis[p][i - 1];
		}
	}
	for (auto x : Graph[src]) {
		int to = x.F;
		int w = x.S;
		if (to != par) {
			dis2[to] = dis2[src] + w;
			dfs(to, src, l + 1, w);
		}
	}
}

int find_lca(int a, int b) {
	if (level[a] > level[b])
		swap(a, b);

	int diff = level[b] - level[a];
	while (diff > 0) {
		int i = log2(diff);
		b = lca[b][i];
		diff -= (1 << i);
	}
	if (a == b)
		return a;

	REV(i, 16, 0) {
		if (lca[a][i] != -1 && (lca[a][i] != lca[b][i])) {
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}

//bcz lca is always on path b/w a and b;
int distance(int a, int LCA) {
	int d = level[a] - level[LCA];

	int ans = 0;

	while (d > 0) {
		int i = log2(d);

		ans += dis[a][i];

		a = lca[a][i];
		d -= (1 << i);
	}
	return ans;
}

int distance2(int a, int b) {
	int LCA = find_lca(a, b);
	int ans = dis2[a] + dis2[b] - 2 * dis2[LCA];
	return ans;
}

void solve() {

	REP(i, 0, N - 1) {
		REP(j, 0, 16) {
			lca[i][j] = -1;
		}
		Graph[i].clear();
		level[i] = 0;
		dis2[i] = 0;
	}
	cin >> n;

	REP(i, 1, n - 1) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}

	dfs(0, -1, 0, -1);

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		//m-I (distance);
		// int LCA = find_lca(a, b);
		// int ans = distance(a, LCA);
		// ans += distance(b, LCA);
		// cout << ans << endl;

		//m-II (distance2);
		cout << distance2(a, b) << endl;
	}

	return ;
}

int main() {

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

	solve();

	return 0;
}