#include <iostream>
#include <vector>
#include <set>
#include <cstring>
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
int entry[N];
int low[N];
int timer;
set <int> ans;
int n, m;

void dfs(int src, int par) {
	vis[src] = 1;
	int children = 0;
	entry[src] = low[src] = timer++;
	for (auto to : Graph[src]) {
		if (to == par)
			continue;
		if (vis[to]) {
			low[src] = min(low[src], entry[to]);
		}
		else {
			dfs(to, src);
			low[src] = min(low[src], low[to]);
			if (low[to] >= entry[src] && par != -1) {
				ans.insert(src);
			}
			children++;
		}
	}
	if (par == -1 && children > 1) {
		ans.insert(src);
	}
}

void articulations(int n) {
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i, -1);
			//cout << ans.size() << endl;
			for (auto x : ans)
				cout << x << endl;
		}
	}
}

void solve() {

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	//articulations(n);
	dfs(1, -1);
	for (auto x : ans)
		cout << x << endl;


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