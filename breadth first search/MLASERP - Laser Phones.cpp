#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod (int)1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e2 + 5;
char Graph[N][N];
int dis[N][N];
int n, m;

void bfs(int sx, int sy) {
	queue <P> q;
	q.push({sx, sy});
	dis[sx][sy] = 0;

	while (!q.empty()) {
		int cur_x = q.front().F;
		int cur_y = q.front().S;
		q.pop();

		int u = cur_x;
		int v = cur_y;

		while (v <= m && Graph[cur_x][v] != '*') {
			if (dis[cur_x][v] > dis[cur_x][cur_y] + 1) {
				dis[cur_x][v] = dis[cur_x][cur_y] + 1;
				q.push({cur_x, v});
			}
			v++;
		}
		v = cur_y;

		while (v >= 1 && Graph[cur_x][v] != '*') {
			if (dis[cur_x][v] > dis[cur_x][cur_y] + 1) {
				dis[cur_x][v] = dis[cur_x][cur_y] + 1;
				q.push({cur_x, v});
			}
			v--;
		}

		while (u <= n && Graph[u][cur_y] != '*') {
			if (dis[u][cur_y] > dis[cur_x][cur_y] + 1) {
				dis[u][cur_y] = dis[cur_x][cur_y] + 1;
				q.push({u, cur_y});
			}
			u++;
		}
		u = cur_x;

		while (u >= 1 && Graph[u][cur_y] != '*') {
			if (dis[u][cur_y] > dis[cur_x][cur_y] + 1) {
				dis[u][cur_y] = dis[cur_x][cur_y] + 1;
				q.push({u, cur_y});
			}
			u--;
		}
	}
}

void solve() {

	REP(i, 0, N) {
		REP(j, 0, N) {
			dis[i][j] = 101;
		}
	}

	cin >> m >> n;
	vector <P> se;
	REP(i, 1, n) {
		REP(j, 1, m) {
			cin >> Graph[i][j];
			if (Graph[i][j] == 'C')
				se.pb({i, j});
		}
	}
	int x1 = se[0].F, y1 = se[0].S;
	int x2 = se[1].F, y2 = se[1].S;
	//cout << x1 << " " << y1 << endl;
	//cout << x2 << " " << y2 << endl;

	bfs(x1, y1);
	cout << dis[x2][y2] - 1 << endl;

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