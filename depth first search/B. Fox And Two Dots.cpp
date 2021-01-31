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

const int N = 60;
char Graph[N][N];
bool vis[N][N];
int edge[N][N];
int n, m;
int cnt = 1;

int row[] = {0, 0, 0, -1, 1};
int col[] = {0, -1, 1, 0, 0};

bool valid(int i, int j) {
	return (i >= 1 && j >= 1 && i <= n && j <= m);
}

bool dfs(int sx, int sy, int px, int py) {

	if (vis[sx][sy]) {
		//cout << cnt << " " << edge[sx][sy] << endl;

		if (cnt - edge[sx][sy] > 1) {
			return true;
		}
		return false;
	}

	vis[sx][sy] = true;
	edge[sx][sy] = cnt;
	cnt++;

	//cout << sx << " " << sy << endl;

	REP(i, 1, 4) {
		int r = sx + row[i];
		int c = sy + col[i];
		if (valid(r, c) && Graph[r][c] == Graph[sx][sy]
		        && !(r == px && c == py)) {//to!=par;
			if (dfs(r, c, sx, sy))
				return true;
		}
	}
	return false;
}

void solve() {

	cin >> n >> m;
	REP(i, 1, n) {
		REP(j, 1, m) {
			cin >> Graph[i][j];
		}
	}

	REP(i, 1, n) {
		REP(j, 1, m) {
			if (!vis[i][j])
				if (dfs(i, j, i, j)) {
					cout << "Yes" << endl;
					return ;
				}
		}
	}
	cout << "No" << endl;

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