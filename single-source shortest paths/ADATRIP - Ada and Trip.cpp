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

const int N = 5e5 + 5;
vector <P> Graph[N];
const int inf = 1e18;
int city[N];
P ans[N];//important;
int n, m, q;

P dijsktra(int src) {
	vector <int> dis(N + 1, inf);
	priority_queue <P, vector<P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		int prev = temp.S;
		int prev_c = temp.F;
		if (prev_c > dis[prev])
			continue;
		for (auto to : Graph[prev]) {
			int cost = to.S;
			int cur = to.F;
			if (dis[cur] > prev_c + cost) {
				dis[cur] = prev_c + cost;
				q.push({dis[cur], cur});
			}
		}
	}
	int cnt = 0;
	int distant = -1;
	for (int i = 0; i < N; i++) {
		if (dis[i] == inf)
			continue;
		if (distant == dis[i])
			cnt++;
		if (dis[i] > distant) {
			cnt = 1;
			distant = dis[i];
		}
	}
	return {distant, cnt};
}

void solve() {
	cin >> n >> m >> q;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	while (q--) {
		int v; cin >> v;
		if (!city[v]) {
			city[v] = 1;
			ans[v] = dijsktra(v);//important;
		}
		cout << ans[v].F << " " << ans[v].S << endl;
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

	//int t; cin >> t; while (t--)
	solve();

	return 0;
}