#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 5e2 + 5;
vector <P> Graph[N];
vector <int> dis;
vector <int> par[N];
const int inf = 1e18;
int n, m;
int s, d;

vector <P> sp;
int vis[N];

typedef vector<int> vi;

void dijkstra(int src) {
	priority_queue <P, vector<P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	//par[src].pb(src);
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		int prev = temp.S;
		int p_c = temp.F;
		if (p_c > dis[prev])
			continue;
		for (auto to : Graph[prev]) {
			if (dis[to.F] >= p_c + to.S) {
				if (dis[to.F] > p_c + to.S) {
					par[to.F].clear();
					par[to.F].pb(prev);
				}
				else {
					par[to.F].pb(prev);
				}
				dis[to.F] = p_c + to.S;
				q.push({dis[to.F], to.F});
			}
		}
	}
}

void dfs(int src, int des) {
	vis[src] = 1;
	if (src == des)
		return ;
	for (auto to : par[src]) {
		if (!vis[to]) {
			dfs(to, des);
			sp.pb({to, src});
		}
	}
}

void dijkstra_1(int src) {
	priority_queue <P, vector<P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		int prev = temp.S;
		int p_c = temp.F;
		if (p_c > dis[prev])
			continue;
		for (auto to : Graph[prev]) {
			if (dis[to.F] > p_c + to.S) {
				dis[to.F] = p_c + to.S;
				q.push({dis[to.F], to.F});
			}
		}
	}
}

void solve() {
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			return ;
		cin >> s >> d;

		for (int i = 0; i < n; i++) {
			Graph[i].clear();
			par[i].clear();
		}
		sp.clear();
		memset(vis, 0, sizeof(vis));

		while (m--) {
			int u, v, w; cin >> u >> v >> w;
			Graph[u].pb({v, w});
		}
		dis = vi(N, inf);
		dijkstra(s);

		dfs(d, s);

		// for (auto x : sp)
		// 	cout << x.F << " " << x.S << endl;

		for (auto x : sp) {
			int tem = x.S;
			int cur = x.F;
			for (auto y = Graph[cur].begin(); y != Graph[cur].end(); y++) {
				P del = *y;
				if (del.F == tem) {
					Graph[cur].erase(y);
					break;
				}
			}
		}
		dis = vi(N, inf);
		dijkstra_1(s);

		if (dis[d] != inf)
			cout << dis[d] << endl;
		else
			cout << -1 << endl;
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