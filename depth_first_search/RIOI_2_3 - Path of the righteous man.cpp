#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define int long long
#define F first
#define S second
#define P pair<int,int>
#define endl '\n'

const int N = 5e1 + 5;
int Graph[N][N];
int vis[N][N];
int key[11];
int ans;
int n;

int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool is_valid(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < n);
}

bool bfs(int x1, int y1, int ex, int ey) {

	if (!key[Graph[x1][y1]] || !key[Graph[ex][ey]]) {
		return false;
	}

	queue <P> q;
	q.push({x1, y1});

	vis[x1][y1] = 1;

	while (!q.empty()) {

		P temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {

			int r = temp.F + row[i];
			int c = temp.S + col[i];

			if (is_valid(r, c) && key[Graph[r][c]] && !vis[r][c]) {

				if (r == ex && c == ey) {
					return true;
				}

				vis[r][c] = 1;
				q.push({r, c});
			}
		}
	}
	return false;
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Graph[i][j];
		}
	}

	int x1, y1; cin >> x1 >> y1;

	int x2, y2; cin >> x2 >> y2;

	if (x1 == x2 && y1 == y2) {
		cout << 1 << endl;
		return ;
	}

	ans = 1000;

	for (int i = 1; i < 1024; i++) {

		int cnt = 0;

		memset(key, 0, sizeof(key));

		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) {
				key[j] = 1;
				cnt++;
			}
		}

		if (ans > cnt) {
			memset(vis, 0, sizeof(vis));

			if (bfs(x1, y1, x2, y2)) {
				ans = cnt;
			}
		}
	}
	cout << ans << endl;

	return ;
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