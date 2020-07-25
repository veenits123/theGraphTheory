#include <iostream>
#include <vector>
#include <queue>
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

const int N = 1e4 + 5;
vector <P> Graph[N + 1];
vector <P> transpose[N + 1];
vector <int> dis;
vector <int> dis_s;
vector <int> dis_e;
const int inf = 1e18;
int n, m, k, s, e;

typedef vector<int> vi;

void dijkstra(int src, vector<P> gr[]) {
	priority_queue <P, vector<P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		int p_c = temp.F;
		int prev = temp.S;
		if (p_c > dis[prev])
			continue;
		for (auto to : gr[prev]) {
			if (dis[to.F] > p_c + to.S) {
				dis[to.F] = p_c + to.S;
				q.push({dis[to.F], to.F});
			}
		}
	}
}

void solve() {
	cin >> n >> m >> k >> s >> e;
	dis_s = vi(N, 0);
	dis_e = vi(N, 0);
	for (int i = 0; i <= N; i++) {
		Graph[i].clear();
		transpose[i].clear();
	}
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		transpose[v].pb({u, w});
	}

	dis = vi(N, inf);
	dijkstra(s, Graph);
	for (int i = 1; i <= n; i++) {
		dis_s[i] = dis[i];
	}

	dis = vi(N, inf);
	dijkstra(e, transpose);
	for (int i = 1; i <= n; i++) {
		dis_e[i] = dis[i];
	}

	// for (int i = 1; i <= n; i++) {
	// 	cout << dis_s[i] << " ";
	// }

	int ans = dis_s[e];
	while (k--) {
		int a, b, c; cin >> a >> b >> c;
		int dis1 = dis_s[a] + c + dis_e[b];
		int dis2 = dis_s[b] + c + dis_e[a];
		ans = min(ans, min(dis1, dis2));
	}
	if (ans != inf)
		cout << ans << endl;
	else
		cout << -1 << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}