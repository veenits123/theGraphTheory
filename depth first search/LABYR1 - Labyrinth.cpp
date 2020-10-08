#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cstring>
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
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e3 + 5;
char Graph[N][N];
int vis[N][N];
int max_dis;
int sx, sy;
int r, c;

int row[] = {0, 0, 0, 1, -1};
int col[] = {0, -1, 1, 0, 0};

bool is_valid(int i, int j) {
	return (i >= 1 && i <= r && j >= 1 && j <= c && Graph[i][j] == '.');
}

void dfs(int x, int y, int dis) {
	vis[x][y] = 1;
	if (dis > max_dis) {
		max_dis = dis;
		sx = x;
		sy = y;
	}
	REP(i, 1, 4) {
		int xxx = row[i] + x;
		int yyy = col[i] + y;
		if (is_valid(xxx, yyy) && !vis[xxx][yyy]) {
			dfs(xxx, yyy, dis + 1);
		}
	}
}

void solve() {

	//memset(Graph, 0, sizeof(Graph));
	memset(vis, 0, sizeof(vis));

	int x = 1, y = 1;
	bool flag = false;
	max_dis = -1;
	sx = -1, sy = -1;

	cin >> c >> r;
	REP(i, 1, r) {
		REP(j, 1, c) {
			cin >> Graph[i][j];
			if (Graph[i][j] == '.' && !flag) {
				flag = true;
				x = i, y = j;
			}
		}
	}
	//cout << x << " " << y << endl;
	dfs(x, y, 0);

	max_dis = -1;
	memset(vis, 0, sizeof(vis));

	dfs(sx, sy, 0);
	cout << "Maximum rope length is " << max_dis << "." << endl;

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