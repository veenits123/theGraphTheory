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

const int N = 2e3 + 5;
char Graph[N][N];
int disl[N][N], disr[N][N];
int vis[N][N];
int n, m;
int sx, sy;
int l, r;
int ans;

typedef vector <int> vi;

int row[5] = {0, 0, 0, -1, 1};
int col[5] = {0, -1, 1, 0, 0};//(0,-1)->left; (0,1)->right;



bool is_valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m && Graph[i][j] != '*');
}

void bfs(int sx, int sy) {

	deque <P> q;
	q.push_front({sx, sy});
	vis[sx][sy] = 1;

	while (!q.empty()) {
		P temp = q.front();
		q.pop_front();
		int tx = temp.F;
		int ty = temp.S;

		if (disl[tx][ty] <= l && disr[tx][ty] <= r)
			ans++;
		//cout << ans;
		for (int i = 1; i <= 4; i++) {
			int r = row[i] + tx;
			int c = col[i] + ty;

			if (!vis[r][c] && is_valid(r, c)) {
				vis[r][c] = 1;

				disl[r][c] = disl[tx][ty] + (i == 1);
				disr[r][c] = disr[tx][ty] + (i == 2);

				if (i == 1 || i == 2)
					q.push_back({r, c});
				else
					q.push_front({r, c});
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	cin >> sx >> sy;
	cin >> l >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
		}
	}
	if (Graph[sx][sy] == '*') {
		cout << 0 << endl;
		return ;
	}
	bfs(sx, sy);
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