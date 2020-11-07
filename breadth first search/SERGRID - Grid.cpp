#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 5e2 + 5;
int Graph[N][N];
int vis[N][N];
int dis[N][N];
int n, m;

int row[] = {0, 0, 0, -1, 1};
int col[] = {0, 1, -1, 0, 0};

bool is_valid(int i, int j) {
	return (i >= 1 && j >= 1 && i <= n && j <= m);
}

void bfs(int sx, int sy, int ex, int ey) {
	queue <pair<int, P>> q;
	q.push({0, {sx, sy}});

	dis[sx][sy] = 0;
	vis[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().S.F;
		int y = q.front().S.S;
		int w = q.front().F;
		q.pop();
		if (w > dis[x][y])
			continue;
		REP(i, 1, 4) {
			int r = row[i] * Graph[x][y] + x;
			int c = y + col[i] * Graph[x][y];
			if (!vis[r][c] && is_valid(r, c)) {
				vis[r][c] = 1;
				q.push({w + 1, {r, c}});
				dis[r][c] = w + 1;
			}
		}
	}
}

void solve() {

	cin >> n >> m;
	REP(i, 1, n) {
		REP(j, 1, m) {
			char x; cin >> x;
			Graph[i][j] = x - '0';
			vis[i][j] = 0;
			dis[i][j] = (int)1e18;
		}
	}

	bfs(1, 1, n, m);

	if (dis[n][m] == (int)1e18) {
		cout << -1 << endl;
		return ;
	}
	cout << dis[n][m] << endl;

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