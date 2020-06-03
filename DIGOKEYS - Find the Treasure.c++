#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

void solve() {
	int n; cin >> n;

	vector <vector<int>> Graph(n);

	for (int i = 1; i < n; i++) {
		int m; cin >> m;
		while (m--) {
			int x; cin >> x;
			Graph[i].pb(x);
		}
		sort(Graph[i].begin(), Graph[i].end());
	}

	int vis[n + 1];
	int par[n + 1];
	memset(vis, 0, sizeof(vis));
	memset(par, -1, sizeof(par));

	bool flag = false;

	queue <int> q;
	q.push(1);
	vis[1] = 1;
	par[1] = -1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (temp == n) {
			flag = true;
			break;
		}
		for (auto to : Graph[temp]) {
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
				par[to] = temp;
			}
		}
	}

	if (flag) {
		vector <int> ans;
		for (int i = n; i != -1; i = par[i]) {
			ans.pb(i);
		}
		reverse(ans.begin(), ans.end());
		ans.pop_back();
		cout << ans.size() << endl;
		for (auto x : ans)
			cout << x << " ";
	}
	else
		cout << -1;

	cout << endl;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}