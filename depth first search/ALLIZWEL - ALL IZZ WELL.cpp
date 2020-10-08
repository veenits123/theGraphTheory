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

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

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

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e2 + 5;
char Graph[N][N];
int vis[N][N];
bool flag;
int n, m;

string alliswell = "ALLIZZWELL";

int row[] = {0, -1, 1, 0, 0, -1, -1, 1, 1};
int col[] = {0, 0, 0, 1, -1, -1, 1, -1, 1};

bool is_valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void dfs(int sx, int sy, int ptr) {
	if (ptr == 10) {
		flag = true;
		return ;
	}
	vis[sx][sy] = 1;
	REP(i, 1, 8) {
		int r = row[i] + sx;
		int c = col[i] + sy;
		if (!vis[r][c] && is_valid(r, c) && Graph[r][c] == alliswell[ptr]) {
			dfs(r, c, ptr + 1);
			if (flag) {
				return ;
			}
		}
	}
	vis[sx][sy] = 0;
}

void solve() {

	memset(vis, 0, sizeof(vis));

	cin >> n >> m;
	REP(i, 1, n) {
		REP(j, 1, m) {
			cin >> Graph[i][j];
		}
	}
	bool ans = false;
	REP(i, 1, n) {
		REP(j, 1, m) {
			if (Graph[i][j] == 'A' && !vis[i][j]) {
				flag = false;
				dfs(i, j, 1);
				if (flag) {
					ans = true;
					break;
				}
			}
		}
		if (ans)
			break;
	}
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

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