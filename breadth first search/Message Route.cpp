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

const int N = 1e5 + 5;
vi Graph[N];
vb vis(N);
vi dis(N);
vi par(N);
int n, m;

void bfs(int src) {
	dis[src] = 0;
	vis[src] = true;;
	queue <int> q;
	q.push(src);
	par[src] = -1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int to : Graph[cur]) {
			if (!vis[to]) {
				vis[to] = true;
				q.push(to);
				dis[to] = dis[cur] + 1;
				par[to] = cur;
			}
		}
	}
}

void solve() {

	vis.assign(N, false);
	dis.assign(N, 0);
	par.assign(N, -1);

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	bfs(1);
	if (!vis[n]) {
		cout << "IMPOSSIBLE" << endl;
		return ;
	}
	cout << dis[n] + 1 << endl;
	vi path;
	for (int i = n; i != -1; i = par[i]) {
		path.pb(i);
	}
	reverse(all(path));
	for (auto x : path)
		cout << x << " ";

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