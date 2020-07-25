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
		int u, v; cin >> u >> v;
		Graph[u].pb({v, 1});
		Graph[v].pb({u, 1});
	}
	//memset(dis, 1000, sizeof(dis));
	for (int i = 0; i <= n; i++) {
		dis[i] = INT_MAX;
	}
	int s, e; cin >> s >> e;

	dijkstra(s);

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