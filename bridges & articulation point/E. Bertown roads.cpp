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

const int N = 1e5 + 5;
vector <int> Graph[N];
int vis[N];
int timer;
int low[N];
int entry[N];
int n, m;
bool flag = true;
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
			
			//method-I;
			// if (ans.count({to, src}) || ans.count({src, to}))
			// 	continue;
			// ans.insert({src, to});

			//method-II;
			if (entry[src] > entry[to])
				ans.insert({src, to});
		}
		else {
			ans.insert({src, to});
			dfs(to, src);
			if (low[to] > entry[src]) {
				flag = false;
				return ;
			}
			low[src] = min(low[src], low[to]);
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
	dfs(1, -1);
	if (flag) {
		for (auto x : ans) {
			cout << x.F << " " << x.S << endl;
		}
	}
	else {
		cout << 0 << endl;
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