#include <iostream>
#include <vector>
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

const int inf = 1e9;
const int N = 1e4 + 5;
vector <pair<P, int>> Graph;
vector <int> dis(N, inf);
int n, m;

void bellman_ford(int src) {
	dis[src] = 0;
	for (;;) {
		bool flag = false;
		for (int j = 0; j < m; j++) {
			int cost = Graph[j].S;
			int par = Graph[j].F.F;
			int child = Graph[j].F.S;
			if (dis[child] > dis[par] + cost) {
				dis[child] = dis[par] + cost;
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		Graph.pb({{u, v}, w});
	}
	bellman_ford(1);
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
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