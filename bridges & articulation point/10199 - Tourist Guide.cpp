#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <map>
#include <algorithm>
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

const int N = 1e2 + 5;
vector <int> Graph[N];
int vis[N];
int entry[N];
int low[N];
int timer;
set <string> ans;
vector <string> final;
int n, m;
map <string, int> key;
map <int, string> node;

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
				ans.insert(node[src]);
			}
			children++;
		}
	}
	if (par == -1 && children > 1) {
		ans.insert(node[src]);
	}
}

void solve() {
	int tc = 1;
	while (true) {
		cin >> n;

		if (n == 0)
			return ;

		memset(vis, 0, sizeof(vis));
		memset(entry, -1, sizeof(entry));
		memset(low, -1, sizeof(low));
		memset(Graph, 0, sizeof(Graph));
		timer = 0;
		ans.clear();
		node.clear();
		key.clear();
		final.clear();

		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			node[i] = s;
			key[s] = i;
		}
		cin >> m;
		while (m--) {
			string u, v; cin >> u >> v;
			Graph[key[u]].pb(key[v]);
			Graph[key[v]].pb(key[u]);
		}
		dfs(1, -1);
		cout << "City map #" << tc++ << ": " << ans.size() << " camera(s) found" << endl;

		for (auto x : ans)
			final.pb(x);

		sort(final.begin(), final.end());
		for (auto x : final)
			cout << x << endl;

		cout << endl;
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