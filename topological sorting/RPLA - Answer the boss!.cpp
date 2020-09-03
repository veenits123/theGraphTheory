#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

const int N = 1e3 + 5;
vector <int> Graph[N];
vector <P> ans, topo;
vector <int> indeg;
int n, m;

typedef vector <int> vi;

void kahn(int n) {
	priority_queue <P, vector<P>, greater<P>> q;
	for (int i = 0; i < n; i++) {
		if (indeg[i] == 0)
			q.push({i, 1});
	}
	while (!q.empty()) {
		P cur = q.top();
		q.pop();

		int level = cur.S;
		int node = cur.F;

		topo.pb(cur);

		for (auto to : Graph[node]) {
			indeg[to]--;
			if (indeg[to] == 0)
				q.push({to, level + 1});
		}
	}
}

void solve() {
	ans.clear();
	indeg = vi(N, 0);
	topo.clear();

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		Graph[i].clear();

	while (m--) {
		int u, v; cin >> u >> v;
		Graph[v].pb(u);
		indeg[u]++;
	}
	kahn(n);

	for (auto x : topo)
		ans.pb({x.S, x.F});
	sort(ans.begin(), ans.end());

	for (auto x : ans)
		cout << x.F << " " << x.S << endl;

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