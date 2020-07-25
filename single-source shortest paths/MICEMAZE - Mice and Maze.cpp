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

const int N = 1e2 + 5;
vector <P> Graph[N];
vector <int> dis;
int n, m, t, e;
const int inf = 1e18;

typedef vector<int> vi;

void dijkstra(int src) {
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
		for (auto to : Graph[prev]) {
			if (dis[to.F] > p_c + to.S) {
				dis[to.F] = p_c + to.S;
				q.push({dis[to.F], to.F});
			}
		}
	}
}

void solve() {
	cin >> n;
	cin >> e;
	cin >> t;
	cin >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[v].pb({u, w});
	}
	dis = vi(N, inf);
	dijkstra(e);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] <= t)
			ans++;
	}
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