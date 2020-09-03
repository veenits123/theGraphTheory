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
vi Graph[N];
vi color;
vi parent;
int c_start, c_end;
int n, m;

//undirected Graph;
bool dfs(int src, int par) {
	color[src] = 1;
	for (auto to : Graph[src]) {
		if (par == to)
			continue;

		if (color[to] == 0) {
			parent[to] = src;
			if (dfs(to, parent[to])) {
				return true;
			}
		}
		else {
			if (color[to] == 1 && to != par) {
				c_start = to;
				c_end = src;
				return true;
			}
		}
	}
	color[src] = 2;
	return false;
}

void cyclic_path() {

	color.assign(N, 0);
	parent.assign(N, -1);
	c_start = -1;

	for (int i = 1; i <= n; i++) {
		if (color[i] == 0)
			if (dfs(i, -1))
				break;
	}
	if (c_start == -1)
		cout << "NO CYCLE!" << endl;
	else {
		vi path;
		path.pb(c_start);

		for (int i = c_end; i != c_start; i = parent[i]) {
			path.pb(i);
		}
		path.pb(c_start);
		reverse(all(path));

		cout << "CYCLE_FOUND!" << endl;
		for (int x : path)
			cout << x << " ";
		cout << endl;
	}
}

void solve() {

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		Graph[i].clear();

	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	cyclic_path();

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