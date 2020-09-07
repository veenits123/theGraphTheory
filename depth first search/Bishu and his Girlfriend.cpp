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

const int N = 1e3 + 5;
vi gr[N];
vi vis;
vi dis;
int n;

void dfs(int src, int d) {
	vis[src] = 1;
	dis[src] = d;
	for (auto to : gr[src]) {
		if (!vis[to])
			dfs(to, d + 1);
	}
}

void solve() {

	vis.assign(N, 0);
	dis.assign(N, 0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	dfs(1, 0);
	int q; cin >> q;
	int ans = 1e3, mxd = 1e3;
	while (q--) {
		int x; cin >> x;
		if (dis[x] <= mxd) {
			ans = min(ans, x);
			mxd = dis[x];
		}
	}
	cout << ans << endl;

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