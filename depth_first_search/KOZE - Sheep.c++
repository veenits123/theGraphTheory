#include <iostream>

using namespace std;

#define int long long
#define endl '\n'

const int N = 3e2;
char Graph[N][N];
int n, m;
int wolves = 0;
int sheep = 0;

int row[5] = {0, 1, -1, 0, 0};
int col[5] = {0, 0, 0, 1, -1};

bool is_valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m && Graph[i][j] != '#');
}

void dfs(int x, int y) {

	if (Graph[x][y] == 'k')
		sheep++;

	if (Graph[x][y] == 'v')
		wolves++;

	Graph[x][y] = '#';

	for (int i = 1; i <= 4; i++) {
		int r = x + row[i];
		int c = y + col[i];

		if (is_valid(r, c))
			dfs(r, c);
	}
}

void solve() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
		}
	}

	int sh = 0, wo = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (Graph[i][j] != '#') {

				dfs(i, j);

				if (sheep > wolves) {
					sh += sheep;
				}
				else {
					wo += wolves;
				}
				sheep = 0;
				wolves = 0;
			}
		}
	}
	cout << sh << " " << wo;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}