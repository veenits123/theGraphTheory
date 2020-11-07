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

const int N = 2e5 + 5;
vi Graph[N];
int lca[N][20];
int level[N];
int n;

void dfs(int src, int par, int l = 0) {
	level[src] = l;
	lca[src][0] = par;

	REP(i, 1, 19) {
		if (lca[src][i - 1] != -1) {
			int p = lca[src][i - 1];
			lca[src][i] = lca[p][i - 1];
		}
	}
	for (int to : Graph[src]) {
		if (to != par) {
			dfs(to, src, l + 1);
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

	REV(i, 19, 0) {
		if (lca[a][i] != -1 && (lca[a][i] != lca[b][i])) {
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}

int dist(int a, int b) {
	return (level[a] + level[b] - 2 * level[find_lca(a, b)]);
}

void solve() {

	cin >> n;

	REP(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}

	//100-points ;)
	REP(i, 0, n) {
		REP(j, 0, 19) {
			lca[i][j] = -1;
		}
		level[i] = 0;
	}
	dfs(1, -1);
	int q; cin >> q;
	while (q--) {
		int r, u, v; cin >> r >> u >> v;

		int LCA = find_lca(u, v);
		int lu = find_lca(r, u);
		int lv = find_lca(r, v);

		map <int, int> ans;

		// int for_r = dist(r, u) + dist(r, v) + dist(r, r);
		// ans[for_r] = r;
		// int for_u = dist(u, u) + dist(u, v) + dist(u, r);
		// ans[for_u] = u;
		// int for_v = dist(v, u) + dist(v, v) + dist(v, r);
		// ans[for_v] = v;

		//only these 3's will also work :)
		int for_LCA = dist(LCA, u) + dist(LCA, v) + dist(LCA, r);
		ans[for_LCA] = LCA;
		int for_lv = dist(lv, u) + dist(lv, v) + dist(lv, r);
		ans[for_lv] = lv;
		int for_lu = dist(lu, u) + dist(lu, v) + dist(lu, r);
		ans[for_lu] = lu;

		cout << ans.begin()->S << endl;
	}

	//20-points ;)
	// int q; cin >> q;
	// while (q--) {
	// 	int r, u, v; cin >> r >> u >> v;
	// 	REP(i, 0, n) {
	// 		REP(j, 0, 19) {
	// 			lca[i][j] = -1;
	// 		}
	// 		level[i] = 0;
	// 	}
	// 	dfs(r, -1, 0);
	// 	cout << find_lca(u, v) << endl;
	// }

	//60-points ;)
	// map <int, int> mp;
	// vector <pair<int, P>> temp;
	// int q; cin >> q;
	// REP(i, 1, q) {
	// 	int r, u, v; cin >> r >> u >> v;
	// 	mp[r]++;
	// 	temp.pb({r, {u, v}});
	// }
	// vi ans(q + 1);
	// for (auto x : mp) {
	// 	int root = x.F;
	// 	REP(i, 0, n) {
	// 		REP(j, 0, 19) {
	// 			lca[i][j] = -1;
	// 		}
	// 		level[i] = 0;
	// 	}
	// 	dfs(root, -1);
	// 	REP(i, 0, q - 1) {
	// 		int r = temp[i].F;
	// 		int u = temp[i].S.F, v = temp[i].S.S;
	// 		if (r == root) {
	// 			ans[i] = find_lca(u, v);
	// 		}
	// 	}
	// }
	// REP(i, 0, q - 1)
	// cout << ans[i] << endl;

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