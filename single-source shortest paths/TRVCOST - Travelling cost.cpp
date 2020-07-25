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

const int N = 5e2 + 5;
vector <P> Graph[N];
vector <int> dis;
int n;
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	dis = vi(N, inf);
	int s; cin >> s;
	dijsktra(s);
	int q; cin >> q;
	while (q--) {
		int v; cin >> v;
		if (dis[v] == inf)
			cout << "NO PATH" << endl;
		else
			cout << dis[v] << endl;
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