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
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod (int)1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 3e2 + 5;
int Graph[N][N];
int vis[N][N];
int n, m;
int cnt;

int row[] = {0, 0, 0, -1, 1};
int col[] = { 0, -1, 1, 0, 0};

bool valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void dfs(int sx, int sy) {
	vis[sx][sy] = 1;
	cnt++;
	REP(i, 1, 4) {
		int r = sx + row[i];
		int c = sy + col[i];
		if (!vis[r][c] && valid(r, c) && Graph[r][c] == 1) {
			dfs(r, c);
		}
	}
}

void solve() {

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			return ;

		memset(vis, 0, sizeof(vis));
		memset(Graph, 0, sizeof(Graph));
		cnt = 0;

		REP(i, 1, n) {
			REP(j, 1, m) {
				cin >> Graph[i][j];
			}
		}
		int ans = 0;
		map <int, int> comp;
		REP(i, 1, n) {
			REP(j, 1, m) {
				if (!vis[i][j] && Graph[i][j] == 1) {
					cnt = 0;
					ans++;
					dfs(i, j);
					comp[cnt]++;
				}
			}
		}
		cout << ans << endl;
		for (auto x : comp)
			cout << x.F << " " << x.S << endl;;
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