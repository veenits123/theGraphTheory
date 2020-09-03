#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 2e5 + 5;
vector <int> Graph[N];
int vis[N];
int color[N];
int comp[N];
vector <int> tree[N];
int dp[N];
int ans = 0;
int n;

void dfs(int src, int col, int dia) {

	if (color[src] != col)
		return ;

	vis[src] = 1;
	comp[src] = dia;

	for (auto to : Graph[src]) {
		if (!vis[to])
			dfs(to, col, dia);
	}
}

void dfs2(int src, int par) {
	int mx1 = 0, mx2 = 0;

	for (auto to : tree[src]) {

		if (par == to)
			continue;

		dfs2(to, src);

		int val = dp[to] + 1;

		mx2 = max(val, mx2);

		if (mx2 > mx1)
			swap(mx2, mx1);
	}
	dp[src] = mx1;
	ans = max(ans, mx1 + mx2);
}

void solve() {
	cin >> n;

	memset(vis, 0, sizeof vis);

	for (int i = 1; i <= n; i++)
		cin >> color[i];

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}

	int temp = 0;

	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i, color[i], temp++);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < Graph[i].size(); j++) {

			int to = Graph[i][j];

			if (comp[i] != comp[to])
				tree[comp[i]].pb(comp[to]);
		}
	}

	dfs2(1, -1);

	cout << (ans + 1) / 2;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}