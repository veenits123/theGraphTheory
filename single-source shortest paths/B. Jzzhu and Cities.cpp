#include <iostream>
#include <queue>
#include <vector>
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
//vector <int> dis;
int vis[N];
int n, m, k;
//const int inf = 1e18;
int ans;

//typedef vector<int> vi;

priority_queue <P> q;

void dijkstra(int src) {
	//dis[src] = 0;
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		int u = temp.S;
		int x = 0;
		int prev_dis = temp.F;
		if (u < 0) {
			x = u;
			u = (-1) * u;
			if (vis[u]) {
				ans++;
				continue;
			}
		}
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto to : Graph[u]) {
			//cout << x << endl;//konsa naya road aa rhaa;
			int cost = to.S;
			int v = to.F;
			//cout << cost << " " << prev_dis << endl;
			q.push({(prev_dis - cost), v});
		}
	}
}

void solve() {
	cin >> n >> m >> k;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	//dis = vi(N, inf);
	q.push({0, 1});
	while (k--) {
		int v, w; cin >> v >> w;
		q.push({ -w, -v});
	}
	dijkstra(1);
	cout << ans;

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