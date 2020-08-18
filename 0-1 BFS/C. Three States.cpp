#include <iostream>
#include <deque>
#include <cstring>
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

const int N = 1e3 + 5;
char Graph[N][N];
int dis[4][N][N];
int n, m;

int row[5] = {0, -1, 1, 0, 0};
int col[5] = {0, 0, 0, 1, -1};

bool is_valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m && Graph[i][j] != '#');
}

void bfs() {
	deque <P> q;
	for (int c = '1'; c <= '3'; c++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (Graph[i][j] == c) {
					q.push_back({i, j});
					dis[c - '0'][i][j] = 0;
				}
			}
		}
		while (!q.empty()) {
			int tx = q.front().F;
			int ty = q.front().S;
			q.pop_front();
			for (int i = 1; i <= 4; i++) {
				int x = tx + row[i];
				int y = ty + col[i];
				if (is_valid(x, y)) {
					int road = dis[c - '0'][tx][ty] + (Graph[x][y] == '.');
					if (dis[c - '0'][x][y] > road || dis[c - '0'][x][y] == -1) {
						dis[c - '0'][x][y] = road;
						if (Graph[x][y] == '.')
							q.push_back({x, y});
						else
							q.push_front({x, y});
					}
				}
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
		}
	}
	memset(dis, -1, sizeof(dis));
	bfs();
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dis[1][i][j] != -1 && dis[2][i][j] != -1 && dis[3][i][j] != -1) {
				int temp = dis[1][i][j] + dis[2][i][j]
				           + dis[3][i][j] - 2 * (Graph[i][j] == '.');
				if (ans > temp || ans == -1) {
					ans = temp;
					//cout << ans << endl;
				}
			}
		}
	}
	cout << ans << endl;

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