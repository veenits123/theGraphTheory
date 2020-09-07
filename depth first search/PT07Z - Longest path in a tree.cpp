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

const int N = 1e4 + 5;
vi graph[N];
vi vis;
int des, diameter;
int n;

void dfs(int src, int cnt) {
	vis[src] = 1;
	if (cnt > diameter) {
		diameter = cnt;
		des = src;
	}
	for (auto to : graph[src]) {
		if (!vis[to]) {
			dfs(to, cnt + 1);
		}
	}
}

void solve() {

	vis.assign(N, 0);
	des = -1;
	diameter = -1;

	cin >> n;
	for (int i = 0; i <= n; i++)
		graph[i].clear();

	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	dfs(1, 0);
	vis.assign(N, 0);
	
	diameter = -1;
	dfs(des, 0);
	cout << diameter << endl;

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