#include <iostream>
#include <vector>
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

const int N = 1e5 + 5;
vector <int> Graph[N];
int vis[N];
int timer;
int entry[N];
int low[N];
int n, m;

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
				cout << "B " << src << " -> " << to << endl;
			}
			low[src] = min(low[src], low[to]);
		}
	}
}

void find_bridges() {
	for (int i = 0; i < n; i++) {
		if (!vis[i])
			dfs(i, -1);
	}
}

void solve() {
	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	find_bridges();

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