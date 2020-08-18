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

const int N = 1e3 + 5;
char Graph[N][N];
int vis[N][N];
int n, m, k;
int sx, sy, ex, ey;

#define node pair<P,int>

int row[5] = {0, 1, -1, 0, 0};
int col[5] = {0, 0, 0, -1, 1};

void bfs() {
	queue <node> q;
	q.push({{sx, sy}, 0});
	vis[sx][sy] = 1;
	while (!q.empty()) {
		node temp = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			node cur = temp;
			cur.S++;
			//cout << cur.S << " " << i << endl;
			int j = 1;
			while (j <= k) {
				cur.F.F += row[i];
				cur.F.S += col[i];
				j++;

				if (cur.F.F > n || cur.F.F < 1 || cur.F.S > m || cur.F.S < 1 || vis[cur.F.F][cur.F.S])
					continue;

				if (Graph[cur.F.F][cur.F.S] == '#')
					break;

				if (cur.F.F == ex && cur.F.S == ey) {
					cout << cur.S << endl;
					return ;
				}

				q.push({{cur.F.F, cur.F.S}, cur.S});
				vis[cur.F.F][cur.F.S] = 1;

			}
		}
	}
	cout << -1 << endl;
	return ;
}

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		cout<<Graph[i][j];
	// 	}
	// }
	cin >> sx >> sy >> ex >> ey;
	if (sx == ex && sy == ey) {
		cout << 0 << endl;
		return ;
	}
	bfs();

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