#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 1e5 + 5;
vector <int> Graph[N];
int cat[N];
int n, m;
int ans = 0;

void dfs(int src, int par, int safe) {
	if (safe > m)
		return ;
	int valid = 1;
	for (auto to : Graph[src]) {
		if (to != par) {
			valid = 0;
			dfs(to, src, safe * cat[to] + cat[to]);
		}
	}
	//cout<<src<<" ";
	ans += valid;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> cat[i];
	}
	int x = n;
	x--;
	while (x--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	dfs(1, 0, cat[1]);
	cout << ans;
	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}