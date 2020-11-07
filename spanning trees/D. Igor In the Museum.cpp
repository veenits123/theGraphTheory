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

const int N = 1e3 + 5;
char Graph[N][N];
int vis[N][N];
int p[100005];
int ind;
int ans;
int n, m, k;

int row[] = {0, 1, -1, 0, 0};
int col[] = {0, 0, 0, -1, 1};

bool is_valid(int i, int j) {
	return (i >= 1 && j >= 1 && i <= n && j <= m);
}

void dfs(int x, int y) {
	if (!is_valid(x, y))
		return ;
	if (vis[x][y])
		return ;
	if (Graph[x][y] == '*') {
		ans++;
		return ;
	}
	vis[x][y] = ind;
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x + 1, y);
	dfs(x - 1, y);
}

void solve() {

	cin >> n >> m >> k;
	REP(i, 1, n) {
		REP(j, 1, m) {
			cin >> Graph[i][j];
		}
	}
	REP(i, 1, k) {
		ind = i;
		int x, y; cin >> x >> y;
		ans = 0;

		if (!vis[x][y])
			dfs(x, y);
		else
			ans = p[vis[x][y]];

		p[ind] = ans;

		cout << ans << endl;
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