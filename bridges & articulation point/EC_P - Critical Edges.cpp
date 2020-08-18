#include <bits/stdc++.h>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 7e2 + 5;
vector <int> Graph[N];
int vis[N];
int timer;
int entry[N];
int low[N];
int n, m;
vector <P> ans;

void dfs(int src, int par) {
	vis[src] = 1;
	entry[src] = low[src] = timer;
	timer++;
	for (auto to : Graph[src]) {
		if (to == par)
			continue;
		if (vis[to])
			low[src] = min(low[src], entry[to]);
		else {
			dfs(to, src);
			if (low[to] > entry[src]) {
				//cout << "B " << src << " -> " << to << endl;
				if (to > src) {
					ans.pb({src, to});
				}
				else {
					ans.pb({to, src});
				}
			}
			low[src] = min(low[src], low[to]);
		}
	}
}

void solve() {

	memset(Graph, 0, sizeof(Graph));
	memset(vis, 0, sizeof(vis));
	memset(entry, 0, sizeof(entry));
	memset(low, 0, sizeof(low));
	timer = 0;
	ans.clear();

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	dfs(1, -1);
	if (ans.size()) {
		cout << ans.size() << endl;
		sort(ans.begin(), ans.end());
		for (auto x : ans) {
			cout << x.F << " " << x.S << endl;
		}
	}
	else {
		cout << "Sin bloqueos" << endl;
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

	int t; cin >> t; int tc = t;
	while (t--) {
		cout << "Caso #" << tc - t << endl;
		solve();
	}

	return 0;
}