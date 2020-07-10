#include <iostream>
#include <vector>
#include <algorithm>
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

const int N = 2e1 + 5;
vector <int> Graph[N], transpose[N];
int vis[N];
vector <int> out;
vector <int> comp;
int n, m;

void dfs(int src) {
	vis[src] = 1;
	for (auto to : Graph[src])
		if (!vis[to])
			dfs(to);
	out.pb(src);
}

void dfs2(int src) {
	vis[src] = 1;
	comp.pb(src);
	for (auto to : transpose[src])
		if (!vis[to])
			dfs2(to);
}

void solve() {
	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		transpose[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
	}
	memset(vis, 0, sizeof(vis));
	reverse(out.begin(), out.end());
	int odd = 0, even = 0;
	for (auto x : out) {
		if (!vis[x]) {
			dfs2(x);
			// for (auto x : comp)
			// 	cout << x << " ";
			// cout << endl;
			int sz = comp.size();
			if (sz % 2)
				odd += sz;
			else
				even += sz;
			comp.clear();
		}
	}
	cout << odd - even << endl;

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