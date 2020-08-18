#include <bits/stdc++.h>
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

const int N = 1e5 + 5;
vector <P> Graph[N];
vector <int> dis;
typedef vector <int> vi;
int n, m;

void bfs(int src) {
	dis[src] = 0;
	deque <int> q;
	q.push_front(src);
	while (!q.empty()) {
		int temp = q.front();
		q.pop_front();
		for (auto to : Graph[temp]) {
			if (dis[to.F] > dis[temp] + to.S) {
				dis[to.F] = dis[temp] + to.S;
				if (to.S == 0)
					q.push_front(to.F);
				else
					q.push_back(to.F);
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	dis = vi(N, 1e9);
	bfs(1);
	cout << dis[n];

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