#include <iostream>
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

const int N = 3e2 + 5;
int dis[N][N];
vector <pair<P, int>> add;
int n, q;
int ans[N];
const int inf = 1e9;

void floyd_warshall() {
	for (int k = 1; k <= q; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], min(dis[i][add[k].F.F] + add[k].S + dis[add[k].F.S][j],//i->a->b->j;
				                               dis[i][add[k].F.S] + add[k].S + dis[add[k].F.F][j]));//i->b->a->j;
			}
		}
		for (int ii = 1; ii <= n; ii++) {
			for (int jj = 1; jj <= n; jj++) {
				ans[k] += dis[ii][jj];
			}
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dis[i][j];
		}
	}
	cin >> q;

	add.pb({{0, 0}, 0});
	for (int i = 1; i <= q; i++) {
		int u, v, w; cin >> u >> v >> w;
		add.pb({{u, v}, w});
	}
	floyd_warshall();
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << dis[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 1; i <= q; i++) {
		cout << ans[i] / 2 << " ";
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