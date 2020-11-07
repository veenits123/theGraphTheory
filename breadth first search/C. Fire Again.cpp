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

const int N = 2001;
int vis[N][N];
int dis[N][N];
int fx, fy;
int n, m, k;

int row[] = {0, 0, 0, 1, -1};
int col[] = {0, -1, 1, 0, 0};

bool is_valid(int i, int j) {
	return (i >= 1 && j >= 1 && j <= m && i <= n);
}

queue <P> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		REP(i, 1, 4) {
			int r = row[i] + x;
			int c = col[i] + y;
			if (!vis[r][c] && is_valid(r, c)) {
				dis[r][c] = dis[x][y] + 1;
				vis[r][c] = 1;
				q.push({r, c});
			}
		}
	}
}

void solve() {

	cin >> n >> m;
	cin >> k;

	int mx = 0;
	REP(i, 1, k) {
		int x, y; cin >> x >> y;
		q.push({x, y});
		dis[x][y] = 0;
		vis[x][y] = 1;
	}
	fx = 1, fy = 1;

	bfs();

	REP(i, 1, n) {
		REP(j, 1, m) {
			if (dis[i][j] >= mx) {
				fx = i, fy = j;
				mx = dis[i][j];
			}
		}
	}
	cout << fx << " " << fy << endl;

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