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
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod 1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;
vi graph[N];
vi vis;
vi col;
bool flag;
int n, m;

void bfs(int src, int c) {
	col[src] = c;
	vis[src] = 1;
	queue <int> q;
	q.push(src);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int to : graph[temp]) {
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
				if (col[temp] == 1)
					col[to] = 2;
				else
					col[to] = 1;
			}
			else {
				if (col[to] == col[temp]) {
					flag = false;
					return ;
				}
			}
		}
	}
}

typedef vector <int> vii;

void solve() {

	vis = vii(N, 0);
	col = vii(N, -1);
	flag = true;

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		graph[i].clear();
	while (m--) {
		int u, v; cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	bool temp = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			bfs(i, 1);
			if (!flag) {
				temp = false;
				break;
			}
		}
	}

	if (!temp) {
		cout << "IMPOSSIBLE" << endl;
		return ;
	}
	for (int i = 1; i <= n; i++)
		cout << col[i] << " ";
	cout << endl;

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