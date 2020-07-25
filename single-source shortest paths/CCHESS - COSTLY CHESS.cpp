#include <iostream>
#include <queue>
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

const int N = 9;
//int Graph[N][N];
int dis[N][N];
const int inf = 1e18;

#define node pair<int,P>

int row[] = { -2, 2, -1, 1, -1, 1, -2, 2};
int col[] = {1, 1, 2, 2, -2, -2, -1, -1};

bool is_valid(int i, int j) {
	return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

void dijkstra(int sx, int sy, int ex, int ey) {
	priority_queue<node, vector<node>, greater<node>> q;

	q.push({0, {sx, sy}});
	dis[sx][sy] = 0;

	while (!q.empty()) {
		node temp = q.top();
		q.pop();

		int p_c = temp.F;
		int tx = temp.S.F;
		int ty = temp.S.S;

		if (p_c > dis[tx][ty])
			continue;

		if (tx == ex && ty == ey)
			break;

		for (int i = 0; i < 8; i++) {
			int r = tx + row[i];
			int c = ty + col[i];

			int cur_cost = r * tx + c * ty;

			if (is_valid(r, c) && dis[r][c] > p_c + cur_cost) {
				dis[r][c] = p_c + cur_cost;
				q.push({dis[r][c], {r, c}});
			}
		}
	}
}

void solve() {
	int x1, x2, y1, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				dis[i][j] = inf;
			}
		}
		dijkstra(x1, y1, x2, y2);
		
		if (dis[x2][y2] != inf)
			cout << dis[x2][y2] << endl;
		else
			cout << -1 << endl;
	}

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