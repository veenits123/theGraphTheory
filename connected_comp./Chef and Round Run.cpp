#include <iostream>
#include <vector>
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

const int N = 1e6 + 5;
vector <int> Graph[N];
int vis[N];
vector <int> comp;
int ans;
int n;

void dfs(int src) {
	comp.pb(src);
	vis[src]++;
	if (vis[src] == 2)
		ans++;
	for (auto to : Graph[src]) {
		if (vis[to] < 2) {
			dfs(to);
		}
	}
}

void solve() {
	cin >> n;
	int a[n + 1];

	ans = 0;
	//memset(vis, 0, sizeof(vis));
	//memset(Graph, 0, sizeof(Graph));

	for (int i = 1; i <= n; i++) {

		vis[i] = 0;
		Graph[i].clear();

		cin >> a[i];
		Graph[i].pb((i + a[i]) % n + 1);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			for (int to = 0; to < comp.size(); to++) {
				if (vis[comp[to]] == 1) {
					vis[comp[to]] = 2;
				}
			}
			comp.clear();
		}
	}
	cout << ans << endl;

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