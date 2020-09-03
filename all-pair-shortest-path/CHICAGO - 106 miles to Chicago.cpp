#include <iostream>
#include <iomanip>
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
#define sp(x,y) fixed<<setprecision(y)<<x

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e2 + 5;
double dis[N][N];
int n, m;

void floyd_warshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = max(dis[i][j], dis[i][k] * dis[k][j]);
			}
		}
	}
}

void solve() {
	while (true) {
		cin >> n;
		if (!n)
			return ;
		cin >> m;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				dis[i][j] = 0.0;
			}
		}
		for (int i = 1; i <= m; i++) {
			int u, v;
			double w;
			cin >> u >> v >> w;
			dis[u][v] = w / 100.0;
			dis[v][u] = w / 100.0;
		}
		floyd_warshall();
		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 1; j <= n; j++) {
		// 		cout << dis[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << sp(dis[1][n] * 100.0, 6) << " percent" << endl;
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