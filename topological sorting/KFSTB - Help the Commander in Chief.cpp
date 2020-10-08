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

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e4 + 5;
vi Graph[N];
vi indeg;
vi topo;
int n, m, s, e;

void kahn(int n) {
	queue <int> q;
	REP(i, 1, n) {
		if (indeg[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		topo.pb(cur);
		for (auto to : Graph[cur]) {
			indeg[to]--;
			if (indeg[to] == 0)
				q.push(to);
		}
	}
}

int no_of_paths(int src, int des) {
	vi dp = vi(N, 0);
	reverse(all(topo));

	dp[des] = 1;

	REP(i, 0, topo.size() - 1) {
		for (auto x : Graph[topo[i]]) {
			dp[topo[i]] = dp[topo[i]] % mod + dp[x] % mod;
		}
	}
	return dp[src] % mod;
}

void solve() {

	indeg = vi(N, 0);
	topo.clear();

	cin >> n >> m >> s >> e;
	REP(i, 0, n)
	Graph[i].clear();

	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		indeg[v]++;
	}
	kahn(n);
	cout << no_of_paths(s, e) % mod << endl;

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