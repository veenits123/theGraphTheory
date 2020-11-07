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
vi Graph[N];
int level[N];
int par[N][18];
int n, q;

void dfs(int src, int p, int l) {
	level[src] = l;
	par[src][0] = p;

	REP(i, 1, 17) {
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
	REV(i, 17, 0) {
		if (par[a][i] != -1 && par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

int calc(int f, int s, int t) {
	int fs = lca(f, s);
	int ft = lca(f, t);
	int st = lca(s, t);
	int ans = 0;
	if ((fs == f && ft != f) || (fs != f && ft == f))
		return 1;
	if (fs == f && ft == f) {
		ans = max(ans, level[st] - level[f]);
	}
	else if (fs != f && ft != f) {
		if (fs != ft)
			ans = max(ans, level[f] - max(level[fs], level[ft]));
		else
			ans = max(ans, level[f] + level[st] - 2 * level[fs]);
	}
	return ans+1;
}

void solve() {

	REP(i, 0, N - 1) {
		REP(j, 0, 17) {
			par[i][j] = -1;
		}
		Graph[i].clear();
		level[i] = 0;
	}

	cin >> n >> q;
	REP(i, 2, n) {
		int x; cin >> x;
		Graph[x].pb(i);
		Graph[i].pb(x);
	}
	dfs(1, -1, 0);

	// REP(i, 1, n) {
	// 	for (auto x : Graph[i])
	// 		cout << x << " ";
	// 	cout << endl;
	// }

	// REP(i, 1, n)
	// cout << par[i][0] << " ";

	while (q--) {
		int a, b, c; cin >> a >> b >> c;
		int ans = max(calc(a, b, c), max(calc(b, c, a), calc(c, b, a)));
		cout << ans << endl;
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