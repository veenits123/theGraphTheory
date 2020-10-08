#include <iostream>
#include <vector>
#include <cstring>
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

const int N = 1e5 + 5;
vector <int> Graph[N];
vector <int> transpose[N];
int vis[N];
vector <int> order;
vector <int> component;
int n, m;

void dfs1(int src) {
	vis[src] = 1;
	//corder<<src<<" ";
	for (auto to : Graph[src]) {
		if (!vis[to]) {
			vis[to] = 1;
			dfs1(to);
		}
	}
	order.pb(src);
}

void dfs2(int src) {
	vis[src] = 1;
	component.pb(src);
	for (auto to : transpose[src]) {
		if (!vis[to]) {
			dfs2(to);
		}
	}
}

void solve() {
	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		transpose[v].pb(u);
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs1(i);
		}
	}

	reverse(order.begin(), order.end());

	for (auto x : order)
		cout << x << " ";
	cout << endl;

	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < n; i++) {
		int cur = order[i];
		if (!vis[cur]) {
			dfs2(cur);

			for (auto x : component)
				cout << x << " ";
			cout << endl;
		}
		component.clear();
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