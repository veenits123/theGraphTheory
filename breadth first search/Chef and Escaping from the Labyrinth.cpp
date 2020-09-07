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
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod 1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e3 + 5;
int Graph[N][N];
int vis[N][N];
vector <P> cell[N];
int n, m;

int row[] = {0, 0, 0, -1, 1};
int col[] = {0, 1, -1, 0, 0};

bool is_valid(int i, int j) {
	return (i >= 1 && j <= m && j >= 1 && i <= n);
}

void bfs() {
	for (int type = 1000; type >= 0; type--) {
		for (auto x : cell[type]) {
			if (vis[x.F][x.S])
				continue;
			vis[x.F][x.S] = 1;
			if (type == 0)
				continue;
			REP(1, 4) {
				int r = row[i] + x.F;
				int c = col[i] + x.S;
				if (!vis[r][c] && is_valid(r, c) && Graph[r][c] != -1) {
					cell[type - 1].pb({r, c});
				}
			}
		}
	}
}

void solve() {

	REP(0, N)
	cell[i].clear();

	memset(vis, 0, sizeof(vis));
	memset(Graph, -1, sizeof(Graph));

	cin >> n >> m;
	REP(1, n) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
		}
	}
	REP(1, n) {
		for (int j = 1; j <= m; j++) {
			if (Graph[i][j] >= 1) {
				cell[Graph[i][j]].pb({i, j});
			}
		}
	}
	bfs();
	REP(1, n) {
		for (int j = 1; j <= m; j++) {
			if (Graph[i][j] == -1)
				cout << "B";
			else {
				if (vis[i][j])
					cout << "Y";
				else
					cout << "N";
			}
		}
		cout << endl;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}