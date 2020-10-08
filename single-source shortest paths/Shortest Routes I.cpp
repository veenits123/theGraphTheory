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
vector <P> Graph[N];
vi dis;
vb vis(N);
int n, m;

void dijkstra(int src) {
	priority_queue <P, vector<P>, greater<P> > q;
	q.push({0, src});
	dis[src] = 0;
	while (!q.empty()) {
		int cost = q.top().F;
		int cur = q.top().S;
		q.pop();
		if (vis[cur])//important sometime otherwise gives TLE ;)
			continue;
		vis[cur] = 1;
		for (auto to : Graph[cur]) {
			int w = to.S;
			int node = to.F;
			if (dis[node] > cost + w) {
				dis[node] = cost + w;
				q.push({dis[node], node});
			}
		}
	}
}

void solve() {

	dis.assign(N, 1e18);
	vis.assign(N, false);

	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
	}
	dijkstra(1);

	REP(i, 1, n)
	cout << dis[i] << " ";

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