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
char Graph[N][N];
int vis[N][N];
int n, m;

int row[] = {0, 0, 0, 1, -1};
int col[] = {0, -1, 1, 0, 0};

bool is_valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void bfs(int x, int y) {
	queue <P> q;
	q.push({x, y});
	vis[x][y] = 1;
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			int r = row[i] + temp.F;
			int c = col[i] + temp.S;
			if (!vis[r][c] && is_valid(r, c) && Graph[r][c] != '#') {
				q.push({r, c});
				vis[r][c] = 1;
			}
		}
	}
}

//dfs;
void dfs(int x, int y) {
	vis[x][y] = 1;
	for (int i = 1; i <= 4; i++) {
		int r = row[i] + x;
		int c = col[i] + y;
		if (!vis[r][c] && is_valid(r, c) && Graph[r][c] != '#') {
			dfs(r, c);
		}
	}
}

void solve() {

	memset(vis, 0, sizeof(vis));
	//memset(Graph, '0', sizeof(Graph));

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++) {
	// 		cout << Graph[i][j];
	// 	}
	// 	cout << endl;
	// }
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j] && Graph[i][j] == '.') {
				dfs(i, j);
				ans++;
			}
		}
	}
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