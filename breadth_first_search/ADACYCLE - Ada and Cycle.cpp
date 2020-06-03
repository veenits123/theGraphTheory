#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

#define int long long int
#define pb push_back
#define endl '\n'

const int N = 2e3 + 5;
vector <int> Graph[N];
int vis[N];
int par[N];

bool bfs(int src, int &ans) {
	queue <int> q;
	q.push(src);
	vis[src] = 1;
	par[src] = -1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (auto to : Graph[temp]) {
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
				par[to] = temp;
			}
			else if (src == to) {
				int dis = 0;
				for (int i = temp; i != -1; i = par[i]) {
					dis++;
				}
				ans = dis;
				return true;
			}
		}
	}
	return false;
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			if (x == 1) {
				Graph[i].pb(j);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int ans = INT_MAX;
		memset(vis, 0, sizeof(vis));
		if (!bfs(i, ans))
			cout << "NO WAY" << endl;
		else
			cout << ans << endl;
	}
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	solve();

	return 0;
}