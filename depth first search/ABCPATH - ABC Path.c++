#include <iostream>
#include <cstring>

using namespace std;

#define int long long
#define F first
#define S second
#define P pair<int,int>
#define endl '\n'

const int N = 5e1 + 5;
char Graph[N][N];
int dis[N][N];
int ans = 0;
int n, m;

int row[9] = {0, 0, 0, -1, 1, -1, 1, -1, 1};
int col[9] = {0, 1, -1, 0, 0, 1, -1, -1, 1};

bool is_valid(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void dfs(int r, int c, int d) {
	dis[r][c] = d + 1;
	for (int i = 1; i <= 8; i++) {
		int x = r + row[i];
		int y = c + col[i];
		if (is_valid(x, y) && Graph[x][y] == Graph[r][c] + 1 && dis[x][y] < dis[r][c] + 1) {
			dfs(x, y, dis[r][c]);
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
		memset(dis, 0, sizeof(dis));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (Graph[i][j] == 'A' && dis[i][j] == 0)
					dfs(i, j, 0);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (dis[i][j] > ans) {
					ans = dis[i][j];
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}