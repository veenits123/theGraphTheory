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
char Graph[N][N];
int vis[N][N];
int dis[N][N];
int ans = 0;
int n, m;

int row[9] = {0, 0, 0, -1, 1, -1, 1, -1, 1};
int col[9] = {0, 1, -1, 0, 0, 1, -1, -1, 1};

bool is_valid(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

queue <P> q;

void bfs() {

	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		for (int i = 1; i <= 8; i++) {
			int x = temp.F + row[i];
			int y = temp.S + col[i];
			if (!vis[x][y] && is_valid(x, y) && Graph[x][y] == Graph[temp.F][temp.S] + 1) {
				dis[x][y] = dis[temp.F][temp.S] + 1;
				vis[x][y] = 1;
				q.push({x, y});
				if (dis[x][y] > ans) {
					ans = dis[x][y];
				}
			}
		}
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

	int tc = 0;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			return 0;
		}
		tc++;
		cout << "Case " << tc << ": ";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> Graph[i][j];
			}
		}
		ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(dis, 0, sizeof(dis));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (Graph[i][j] == 'A') {
					q.push({i, j});
					dis[i][j] = 1;
					ans = 1;
				}
			}
		}
		bfs();
		cout << ans << endl;
	}

	return 0;
}