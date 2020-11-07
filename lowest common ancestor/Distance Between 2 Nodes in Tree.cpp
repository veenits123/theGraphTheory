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
vi Graph[N];
int lca[N][17];
int level[N];
int n;

void dfs(int src, int par, int l = 0) {
	level[src] = l;
	lca[src][0] = par;

	REP(i, 1, 16) {
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

	REV(i, 16, 0) {
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

	REP(i, 0, N - 1) {
		REP(j, 0, 16) {
			lca[i][j] = -1;
		}
		Graph[i].clear();
		level[i] = 0;
	}
	cin >> n;

	REP(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	dfs(1, -1);

	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		cout << dist(u, v) << endl;
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