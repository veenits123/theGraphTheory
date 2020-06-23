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

const int N = 2e5 + 5;
vector <int> Graph[N];
int n, x;
int bob[N], alice[N];

void dfs(int src, int par, int depth[]) {
	depth[src] = depth[par] + 1;
	for (auto to : Graph[src]) {
		if (to != par) {
			dfs(to, src, depth);
		}
	}
}

void solve() {
	cin >> n >> x;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	int ans = 0;
	bob[0] = alice[0] = -1;
	dfs(1, 0, alice);
	dfs(x, 0, bob);
	for (int i = 1; i <= n; i++) {
		if (bob[i] < alice[i])
			ans = max(ans, 2 * alice[i]);
	}
	cout << ans;

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