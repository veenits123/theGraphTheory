#include <iostream>
#include <vector>
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
vector <int> vis;
vector <int> ans;
int n, m;

typedef vector <int> vi;

void dfs(int src) {
	vis[src] = 1;
	for (auto to : Graph[src]) {
		if (!vis[to])
			dfs(to);
	}
	ans.pb(src);
}

void topological_sort() {
	ans.clear();
	vis = vi(N, 0);

	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
	}
	reverse(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x << " ";
	cout << endl;
}

void solve() {

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		//Graph[v].pb(u);
	}
	topological_sort();

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