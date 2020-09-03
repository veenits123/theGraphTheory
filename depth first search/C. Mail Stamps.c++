#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define int long long
#define F first
#define S second
#define pb push_back
#define endl '\n'

const int N = 1e5 + 5;
map <int, vector<int>> Graph;
int vis[N];
int n;

void dfs(int src, int par) {
	cout << src << " ";
	for (int i = 0; i < Graph[src].size(); i++) {
		int to = Graph[src][i];
		if (to != par) {
			dfs(to, src);
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	for (auto x : Graph) {
		if (x.S.size() == 1) {
			dfs(x.F, -1);
			break;
		}
	}

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