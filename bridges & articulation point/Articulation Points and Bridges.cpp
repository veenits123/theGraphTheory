#include <iostream>
#include <vector>
#include <set>
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

const int N = 1e1 + 5;
vector <int> Graph[N];
int vis[N];
int entry[N];
int low[N];
int timer;
set <int> ans;
vector <P> bridge;
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
			if (low[to] > entry[src]) {
				if (to > src)
					bridge.pb({src, to});
				else
					bridge.pb({to, src});
			}
			children++;
		}
	}
	if (par == -1 && children > 1) {
		ans.insert(src);
	}
}

void solve() {

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	dfs(0, -1);

	cout << ans.size() << endl;
	for (auto x : ans)
		cout << x << " ";
	cout << endl;

	sort(bridge.begin(), bridge.end());

	cout << bridge.size() << endl;
	for (auto x : bridge)
		cout << x.F << " " << x.S << endl;

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