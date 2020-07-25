#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
#define mp make_pair
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 3e3 + 5;
vector <int> Graph[N];
set <pair<P, int>> forbid;
int vis[N][N];
P par[N][N];
int n, m, k;

P dijkstra(int src) {
	queue <P> q;
	q.push({src, src});
	vis[src][src] = 1;
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		int x = temp.F;
		int y = temp.S;
		if (y == n)
			return temp;
		for (auto to : Graph[y]) {
			if (vis[y][to] || forbid.count({temp, to}))
				continue;
			vis[y][to] = 1;
			par[y][to] = temp;
			q.push({y, to});
		}
	}
	return { -1, -1};
}



void solve() {
	cin >> n >> m >> k;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	while (k--) {
		int x, y, z; cin >> x >> y >> z;
		forbid.insert({{x, y}, z});
	}
	P ans = dijkstra(1);

	if (ans == mp((int) - 1, (int) - 1)) {
		cout << -1 << endl;
		return ;
	}

	vector <int> path;
	for (P i = ans; i != mp((int)1, (int)1); i = par[i.F][i.S]) {
		path.pb(i.S);
	}
	path.pb(1);
	reverse(path.begin(), path.end());
	cout << path.size() - 1 << endl;
	for (auto x : path)
		cout << x << " ";

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