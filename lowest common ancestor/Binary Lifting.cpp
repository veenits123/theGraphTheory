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

const int N = 1e4 + 5;
vi Graph[N];
int lca[N][21];
int level[N];
int n;

void dfs(int src, int par, int l = 0) {
	level[src] = l;
	lca[src][0] = par;

	REP(i, 1, 20) {
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

	REV(i, 20, 0) {
		if (lca[a][i] != -1 && (lca[a][i] != lca[b][i])) {
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	return lca[a][0];
}

void solve() {

	REP(i, 0, N - 1) {
		REP(j, 0, 20) {
			lca[i][j] = -1;
		}
		Graph[i].clear();
		level[i] = 0;
	}

	scanf("%d", &n);
	REP(i, 0, n-1) {
		int x; scanf("%d", &x);
		while (x--) {
			int child; scanf("%d", &child);
			Graph[i].pb(child);
			Graph[child].pb(i);
		}
	}
	dfs(0, -1, 0);

	int q; scanf("%d", &q);
	while (q--) {
		int u, v; scanf("%d", &u); scanf("%d", &v);
		printf("%d\n", find_lca(u, v));
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