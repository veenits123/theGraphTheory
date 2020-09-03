#include <iostream>
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
const int inf = 1e18;
int dis[N][N];
int n, m;
int q;

void floyd_warshall() {
	for (int k = 1; k <= n; k++) {//for generating n matrices;
		//matrices;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

void solve() {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dis[i][j] = 0;
			}
			else if (!dis[i][j])
				dis[i][j] = inf;
		}
	}
	floyd_warshall();

	while (q--) {
		int u, v; cin >> u >> v;
		if (dis[u][v] == inf)
			cout << -1 << endl;
		else
			cout << dis[u][v] << endl;
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