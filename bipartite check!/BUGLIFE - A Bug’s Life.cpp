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

const int N = 2e3 + 5;
vector <int> Graph[N];
vector <int> color;
vector <int> vis;
int n, m;

typedef vector <int> vii;

bool dfs(int src, int col) {
	vis[src] = 1;
	color[src] = col;
	for (int to : Graph[src]) {
		if (!vis[to]) {
			if (dfs(to, col ^ 1) == false)//col^1 -> changing color
				return false;
		}
		else {
			if (color[to] == color[src])
				return false;
		}
	}
	return true;
}

bool flag;

void bfs(int src, int c) {
	color[src] = c;
	vis[src] = 1;
	queue <int> q;
	q.push(src);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int to : Graph[temp]) {
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
				color[to] = color[temp] ^ 1;
			}
			else {
				if (color[to] == color[temp]) {
					flag = false;
					return ;
				}
			}
		}
	}
}

void solve() {

	flag = true;
	vis = vii(N, 0);
	color = vii(N, -1);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		Graph[i].clear();

	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	// bool flag = true;
	// for (int i = 1; i <= n; i++) {
	// 	if (!vis[i])
	// 		if (dfs(i, 1) == false) {
	// 			//cout << i << endl;
	// 			flag = false;
	// 			break;
	// 		}
	// }
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			bfs(i, 1);
			if (!flag) {
				break;
			}
		}
	}
	if (!flag)
		cout << "Suspicious bugs found!" << endl;
	else
		cout << "No suspicious bugs found!" << endl;

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

	int t, tc; cin >> t; tc = t; while (t--) {
		cout << "Scenario #" << tc - t << ":" << endl;
		solve();
	}

	return 0;
}