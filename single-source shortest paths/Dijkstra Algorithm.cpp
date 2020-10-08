#include <iostream>
#include <queue>
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
vector <P> Graph[N];
vector <int> dis(N, 1e18);
//int vis[N];
int par[N];
int n, m;

void dijsktra(int src) {
	priority_queue <P, vector<P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	par[src] = -1;
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		int prev = temp.S;
		int prev_c = temp.F;
		if (vis[prev])//important sometime otherwise gives TLE ;)
			continue;
		vis[prev] = 1;
		for (auto to : Graph[prev]) {
			int cost = to.S;
			int cur = to.F;
			if (dis[cur] > prev_c + cost) {
				dis[cur] = prev_c + cost;
				q.push({dis[cur], cur});
				par[cur] = prev;
			}
		}
	}
}

void shortest_path(int src, int des) {
	if (dis[des] == 1e18) {
		cout << -1 << endl;
		return ;
	}
	vector <int> path;
	for (int i = des; i != src; i = par[i]) {
		path.pb(i);
	}
	path.pb(src);
	reverse(path.begin(), path.end());
	for (auto x : path)
		cout << x << " ";
	return ;
}

void solve() {
	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	dijsktra(1);
	//shortest_path(1, n);
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
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