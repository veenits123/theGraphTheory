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
#define vi vector<int>

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e6 + 5;
vector <int> Graph[N];
vector <int> transpose[N];
int vis[N];
vector <int> out;
vector <int> comp;
int group;
int scc[N];
int cost[N];
vector <int> condensed[N];
int dp[N];
int n, m, s, e;
map <int, int> fun;

void dfs1(int src) {
	vis[src] = 1;
	for (auto to : Graph[src])
		if (!vis[to])
			dfs1(to);
	out.pb(src);
}

void dfs2(int src) {
	vis[src] = 1;
	scc[src] = group;
	cost[group] += fun[src];
	for (auto to : transpose[src])
		if (!vis[to])
			dfs2(to);
}

void shrink(int src) {
	vis[src] = 1;
	for (auto to : condensed[src]) {
		if (!vis[to])
			shrink(to);
	}
	comp.pb(src);
}

int max_fun(int start, int end) {
	for (int i = 0; i < comp.size(); i++) {
		dp[comp[i]] = INT_MAX;
	}
	dp[start] = -cost[start];
	for (int i = comp.size() - 1; i >= 0; i--) {
		int u = comp[i];
		for (auto to : condensed[u]) {
			dp[to] = min(dp[to], dp[u] - cost[to]);
		}
	}
	return -dp[end];
}

void solve() {
	cin >> n >> m >> s >> e;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		fun[i] = x;
	}
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		transpose[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs1(i);
	}
	reverse(out.begin(), out.end());

	memset(vis, 0, sizeof(vis));
	for (auto x : out) {
		if (!vis[x]) {
			group++;
			dfs2(x);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (auto to : Graph[i]) {
			if (scc[i] != scc[to]) {
				condensed[scc[i]].pb(scc[to]);
			}
		}
	}
	memset(vis, 0, sizeof(vis));

	for (int i = 1; i <= group; i++) {
		if (!vis[i])
			shrink(i);
	}
	cout << max_fun(scc[s], scc[e]) << endl;

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