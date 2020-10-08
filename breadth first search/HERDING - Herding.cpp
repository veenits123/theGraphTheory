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

const int N = 1e6 + 5;
char a[1001][1001];
vi Graph[N];
int vis[N];
int n, m;
int ans;

int row[] = {0, 0, 0, -1, 1};//E W N S;
int col[] = {0, 1, -1, 0, 0};

bool is_valid(int i, int j) {
	return (i >= 0 && i <= n - 1  && j >= 0 && j <= m - 1);
}

P cord(char x) {
	if (x == 'S')
		return {1, 0};
	if (x == 'N')
		return { -1, 0};
	if (x == 'E')
		return {0, 1};
	if (x == 'W')
		return {0, -1};
	return {0, 0};
}

void bfs(int src) {
	queue <int> q;
	q.push(src);
	vis[src] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int to : Graph[temp]) {
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
			}
		}
	}
}

void solve() {

	cin >> n >> m;
	REP(i, 0, n - 1) {
		REP(j, 0, m - 1) {
			cin >> a[i][j];
		}
	}
	REP(i, 0, n - 1) {
		REP(j, 0, m - 1) {
			int u = (i * m) + j;
			int v = -1;
			int r = cord(a[i][j]).F + i;
			int c = cord(a[i][j]).S + j;
			if (is_valid(r, c)) {
				v = (r * m) + c;
				Graph[u].pb(v);
				Graph[v].pb(u);
			}
			//cout << u << " " << v << endl;
		}
	}
	// REP(i, 0, n * m - 1) {
	// 	for (auto x : Graph[i])
	// 		cout << x << " ";
	// 	cout << endl;
	// }
	REP(i, 0, n * m - 1)
	if (!vis[i]) {
		ans++;
		bfs(i);
	}
	cout << ans;

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