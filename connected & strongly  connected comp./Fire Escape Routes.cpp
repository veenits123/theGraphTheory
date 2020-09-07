#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vi graph[N];
vi vis;
vi comp;
int n, m;

void dfs(int src) {
	vis[src] = 1;
	comp.pb(src);
	for (int to : graph[src]) {
		if (!vis[to])
			dfs(to);
	}
}

void connected_comp() {
	vis.assign(N, 0);
	comp.clear();
	vector <vi> ans;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans.pb(comp);
		}
		comp.clear();
	}
	cout << ans.size() << " ";
	int res = 1;
	for (auto x : ans) {
		res = res * x.size() % mod;
	}
	cout << res % mod << endl;
}

void solve() {

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		graph[i].clear();
	while (m--) {
		int u, v; cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	connected_comp();
	//cout << ncr(3) << endl;

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