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
vector <int> dis;
int n, m;
int s, e;
const int inf = 1e18;

typedef vector<int> vi;

void dijsktra(int src) {
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
}

void solve() {
	dis = vi(N, inf);

	cin >> n >> m >> s >> e;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	dijsktra(s);
	if (dis[e] == inf)
		cout << "NONE" << endl;
	else
		cout << dis[e] << endl;
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