#include <iostream>
#include <deque>
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

const int N = 1e3 + 5;
char Graph[N][N];
int dis[N][N];
int n, m;

int row[] = {0, -1, 1, 0};
int col[] = {1, 0, 0, -1};

bool is_valid(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs() {
	deque <P> q;
	q.push_front({0, 0});
	dis[0][0] = 0;
	while (!q.empty()) {
		int tx = q.front().F;
		int ty = q.front().S;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int r = tx + row[i];
			int c = ty + col[i];
			if (is_valid(r, c)) {
				int w = 0;
				if (Graph[r][c] != Graph[tx][ty])
					w = 1;
				if (dis[r][c] > dis[tx][ty] + w) {
					dis[r][c] = dis[tx][ty] + w;
					if (w == 0)
						q.push_front({r, c});
					else
						q.push_back({r, c});
				}
			}
		}
	}
}

void solve() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Graph[i][j] = '0';
			dis[i][j] = 1e9;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> Graph[i][j];
		}
	}
	bfs();
	cout << dis[n - 1][m - 1] << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}