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
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e6 + 5;
vector <P> Graph[N];
vector <P> transpose[N];
vi dis;
int n, m;

void dijkstra(int src) {
	priority_queue <P, vector <P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	while (!q.empty()) {
		int cur = q.top().S;
		int cost = q.top().F;
		q.pop();
		if (cost > dis[cur]) {
			return ;
		}
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

void dijkstra1(int src) {
	priority_queue <P, vector <P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	while (!q.empty()) {
		int cur = q.top().S;
		int cost = q.top().F;
		q.pop();
		if (cost > dis[cur]) {
			return ;
		}
		for (auto to : transpose[cur]) {
			int w = to.S;
			int node = to.F;
			if (dis[node] > dis[cur] + w) {
				dis[node] = dis[cur] + w;
				q.push({dis[node], node});
			}
		}
	}
}

void solve() {

	dis.assign(N, 1e18);

	cin >> n >> m;
	REP(i, 0, n) {
		Graph[i].clear();
		transpose[i].clear();
	}

	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		transpose[v].pb({u, w});
	}
	dijkstra(1);

	int jane_ka = 0;
	REP(i, 1, n) {
		//cout << dis[i] << " ";
		jane_ka += dis[i];
	}
	dis.assign(N, 1e18);

	dijkstra1(1);

	int aane_ka = 0;
	REP(i, 1, n) {
		aane_ka += dis[i];
	}
	cout << jane_ka + aane_ka << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}