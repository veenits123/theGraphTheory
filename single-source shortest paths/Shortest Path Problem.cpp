#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <set>
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
int vis[N];
int dis[N];
int n, m;

void dijkstra(int src) {

	dis[src] = 0;

	priority_queue<P, vector<P>, greater<P> > q;
	q.push({0, src});

	while (!q.empty()) {

		P temp = q.top();
		q.pop();

		int node = temp.S;
		//cout << node << " ";

		if (vis[node])
			continue;
		vis[node] = 1;

		for (auto to : Graph[node]) {
			int next = to.F;
			int cost = to.S;
			//cout << dis[next] << " ";

			if (dis[next] > cost + dis[node]) {

				dis[next] = cost + dis[node];
				q.push({dis[next], next});
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	//memset(dis, 1000, sizeof(dis));
	for (int i = 0; i <= n; i++) {
		dis[i] = 1e6;
	}

	dijkstra(1);

	for (int i = 2; i <= n; i++) {
		if (dis[i] != 1e6)
			cout << dis[i] << " ";
		else
			cout << -1 << " ";
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