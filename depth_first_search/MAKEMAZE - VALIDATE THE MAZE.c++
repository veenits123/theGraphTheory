#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define int long long
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 2e1 + 5;
char Graph[N][N];
int vis[N][N];
int n, m;

int row[5] = {0, 1, -1, 0, 0};
int col[5] = {0, 0, 0, 1, -1};

bool is_valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void dfs(int x, int y) {
	vis[x][y] = 1;
	for (int i = 1; i <= 4; i++) {
		int r = x + row[i];
		int c = y + col[i];

		if (!vis[r][c] && is_valid(r, c) && Graph[r][c] == '.') {
			dfs(r, c);
		}
	}
}

void solve() {
	cin >> n >> m;

	int gate = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];

			if (Graph[i][j] == '.') {
				if (i == 1 || i == n || j == 1 || j == m) {
					gate++;
				}
			}
		}
	}
	if (gate > 2 || gate < 2) {
		cout << "invalid" << endl;
		return ;
	}

	else {
		vector <P> open;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {

				if (Graph[i][j] == '.') {
					if (i == 1 || i == n || j == 1 || j == m) {
						open.pb({i, j});
					}
				}
			}
		}
		// for(auto x:open)
		// 	cout<<x.F<<" "<<x.S<<endl;

		memset(vis, 0, sizeof(vis));

		int x1 = open[0].F, y1 = open[0].S;

		int x2 = open[1].F, y2 = open[1].S;

		dfs(x1, y1);
		if (vis[x2][y2])
			cout << "valid" << endl;
		else
			cout << "invalid" << endl;
		return ;
	}

}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--)
		solve();

	return 0;
}