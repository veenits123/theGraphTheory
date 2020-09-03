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
int dis[N][N];
int del[N];
int n;
int ans[N];

void floyd_warshall() {
	for (int k = n; k >= 1; k--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][del[k]] + dis[del[k]][j]);
			}
		}
		for (int ii = k; ii <= n; ii++) {
			for (int jj = k; jj <= n; jj++) {
				ans[k] += dis[del[ii]][del[jj]];
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
	for (int i = 1; i <= n; i++) {
		cin >> del[i];
	}
	floyd_warshall();
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";

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