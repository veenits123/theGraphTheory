#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod 1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e4 + 5;
vi graph[N];
vi vis;
int n, m;

bool dfs(int src, int par) {
	vis[src] = 1;
	for (int to : graph[src]) {
		if (to == par)
			continue;
		if (!vis[to]) {
			if (dfs(to, src))
				return true;
		}
		else
			return true;
	}
	return false;
}

void con_comp(int src) {
	vis[src] = 1;
	for (int to : graph[src])
		if (!vis[to])
			con_comp(to);
}

void solve() {

	vis.assign(N, 0);

	cin >> n >> m;
	if (m > n - 1) {
		cout << "NO";
		return ;
	}
	for (int i = 0; i <= n; i++)
		graph[i].clear();

	while (m--) {
		int u, v; cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	//method 1 checking cycle;
	// for (int i = 1; i <= n; i++) {
	// 	if (!vis[i]) {
	// 		if (dfs(i, -1)) {
	// 			cout << "NO" << endl;
	// 			return ;
	// 		}
	// 	}
	// }
	// cout << "YES" << endl;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			con_comp(i), cnt++;
	if (cnt > 1)
		cout << "NO";
	else
		cout << "YES";

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