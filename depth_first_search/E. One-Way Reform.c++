#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define int long long
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 2e2 + 5;
int Graph[N][N];
int degree[N];
int n, m;
vector <P> ans;

void dfs(int src) {
	for (int to = 0; to <= n; to++) {
		if (Graph[src][to]) {
			Graph[src][to]--;
			Graph[to][src]--;
			if (src && to)
				ans.pb({src, to});
			dfs(to);
		}
	}
}

void solve() {

	memset(degree, 0, sizeof(degree));
	memset(Graph, 0, sizeof(Graph));
	ans.clear();

	cin >> n >> m;

	while (m--) {
		int u, v; cin >> u >> v;
		degree[u]++;
		degree[v]++;
		Graph[u][v] = 1;
		Graph[v][u] = 1;
	}

	int res = 0;

	for (int i = 1; i <= n; i++) {
		if (degree[i] & 1) {
			res++;
			Graph[i][0] = 1;
			Graph[0][i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		dfs(i);
	}

	cout << n - res << endl;

	for (auto x : ans)
		cout << x.F << " " << x.S << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}