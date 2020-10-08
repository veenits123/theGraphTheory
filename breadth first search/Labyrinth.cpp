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

const int N = 1e3 + 5;
char Graph[N][N];
int vis[N][N];
int dis[N][N];
pair <P, char> par[N][N];
int n, m;

int row[] = {0, 0, 0, -1, 1};
int col[] = {0, 1, -1, 0, 0};

bool is_valid(int i, int j) {
	return (i >= 1 && j >= 1 && i <= n && j <= m && Graph[i][j] != '#');
}

char dir[] = {'X', 'R', 'L', 'U', 'D'};

void bfs(int sx, int sy, int ex, int ey) {
	queue <P> q;
	q.push({sx, sy});
	dis[sx][sy] = 0;
	vis[sx][sy] = 1;
	while (!q.empty()) {
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		if (ex == x && ey == y)
			return ;
		REP(i, 1, 4) {
			int r = x + row[i];
			int c = y + col[i];
			if (!vis[r][c] && is_valid(r, c)) {
				vis[r][c] = 1;
				q.push({r, c});
				dis[r][c] = dis[x][y] + 1;

				char next = dir[i];
				par[r][c] = {{x, y}, next};
			}
		}
	}
}

void solve() {

	cin >> n >> m;
	P st, e;
	REP(i, 1, n) {
		REP(j, 1, m) {
			cin >> Graph[i][j];
			if (Graph[i][j] == 'A')
				st = {i, j};
			if (Graph[i][j] == 'B')
				e = {i, j};
		}
	}
	bfs(st.F, st.S, e.F, e.S);

	if (!vis[e.F][e.S]) {
		cout << "NO" << endl;
		return ;
	}
	int ex = e.F, ey = e.S;
	string ans = "";

	while (st != e) {
		ans += par[e.F][e.S].S;
		e = par[e.F][e.S].F;
	}
	reverse(all(ans));

	cout << "YES" << endl;
	cout << dis[ex][ey] << endl;
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