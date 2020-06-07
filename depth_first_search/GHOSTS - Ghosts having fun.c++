#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 1e3 + 5;
vector <int> Graph[N];
int vis[N];
bitset <N> cycle[N];
int n, m;

void dfs(int src) {
	vis[src] = 1;
	//cout<<src<<" ";
	for (auto to : Graph[src]) {
		if (!vis[to]) {
			dfs(to);
		}

		cycle[src] |= cycle[to];
		cycle[src].set(to);
	}
	//cout<<endl;
}

void solve() {
	cin >> n;
	cin >> m;

	while (m--) {
		int u, v; cin >> u >> v;

		if (cycle[v][u] || u == v) {
			cout << u << " " << v << endl;
		}

		else if (cycle[u][v]) {
			continue;
		}

		else {
			Graph[u].pb(v);
			memset(vis, 0, sizeof vis);

			for (int i = 1; i <= n; i++) {
				if (!vis[i])
					dfs(i);
			}

		}
	}

	cout << 0 << " " << 0 << endl;

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