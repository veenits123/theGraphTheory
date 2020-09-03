#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 3e2 + 5;
vector <int> Graph[N];
int vis[N];
int n;
vector <int> ans;
int des, start;

bool dfs(int src, int par, int aim) {

	if (src == aim)
		return true;
	//cout<<src<<" ";

	for (auto to : Graph[src]) {
		if (to != par) {

			if (dfs(to, src, aim)) {
				ans.pb(src);
				return true;
			}
		}
	}
	//cout<<endl;
	return false;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	ans.pb(1);

	start = 1;

	while (cin >> des) {
		dfs(des, -1, start);
		start = des;
	}

	dfs(1, -1, start);

	if (ans.size() != 2 * n - 1)
		cout << -1;
	else
		for (auto x : ans)
			cout << x << " ";

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