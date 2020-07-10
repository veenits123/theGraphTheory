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

const int N = 1e3 + 5;
vector <int> Graph[N];
int vis[N];
int timer;
int low[N];
int entry[N];
int n, m;
set <P> ans;

void dfs(int src, int par) {
	vis[src] = 1;
	low[src] = entry[src] = timer;
	timer++;
	for (auto to : Graph[src]) {
		if (to == par)
			continue;
		if (vis[to]) {
			low[src] = min(low[src], entry[to]);

			//method-II;
			if (entry[src] > entry[to])
				ans.insert({src, to});
		}
		else {
			ans.insert({src, to});
			dfs(to, src);

			if (low[to] > entry[src]) {
				ans.insert({src, to});
				ans.insert({to, src});
			}
			low[src] = min(low[src], low[to]);
		}
	}
}

void solve() {

	int tc = 1;

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			return ;

		for (int i = 0; i <= N; i++)
			Graph[i].clear();

		memset(vis, 0, sizeof(vis));
		memset(entry, -1, sizeof(entry));
		memset(low, -1, sizeof(low));
		timer = 0;
		ans.clear();

		cout << tc++ << endl << endl;

		while (m--) {
			int u, v; cin >> u >> v;
			Graph[u].pb(v);
			Graph[v].pb(u);
		}
		dfs(1, -1);

		for (auto x : ans) {
			cout << x.F << " " << x.S << endl;
		}

		cout << '#' << endl;
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