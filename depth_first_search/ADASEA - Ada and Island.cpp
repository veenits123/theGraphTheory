#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long
#define endl '\n'

const int N = 1e3 + 5;
char Graph[N][N];
int vis[N][N];
int safe = 0;
int n, m;

int row[5] = {0, 1, -1, 0, 0};
int col[5] = {0, 0, 0, 1, -1};

bool is_valid(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void dfs(int x, int y) {
	vis[x][y] = 1;
	safe++;
	//cout << safe << " ";

	for (int i = 1; i <= 4; i++) {
		int r = x + row[i];
		int c = y + col[i];
		if (!vis[r][c] && is_valid(r, c) && Graph[r][c] == '#') {
			dfs(r, c);
		}
	}
}

int gcd(int a, int b) {
	return __gcd(a, b);
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
		}
	}
	memset(vis, 0, sizeof(vis));

	int p = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j] && Graph[i][j] == '#') {
				safe = 0;
				dfs(i, j);
				p += safe * safe;
				//cout << p << endl;
			}
		}
	}
	int q = n * m;

	int ans = gcd(p, q);
	p = p / ans;
	q = q / ans;
	if (q == 1) {
		cout << p << endl;
		return ;
	}
	else {
		cout << p << " / " << q << endl;
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