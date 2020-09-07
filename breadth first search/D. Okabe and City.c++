#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define endl '\n'
#define inf 1e4

const int N = 1e5 + 5;
int row[N], col[N];
int vis[N];
int dis[N];
int n, m, k;

void bfs(int src) {
	queue <int> q;
	q.push(src);
	vis[src] = 1;
	dis[src] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= k; i++) { //i is like cell;
			if (cur == i)
				continue;

			int cost = inf;

			int r = abs(row[i] - row[cur]);
			int c = abs(col[i] - col[cur]);

			if (r + c < 2)
				cost = 0;
			else if (r < 3 || c < 3)
				cost = 1;

			if (dis[i] > dis[cur] + cost) {
				dis[i] = dis[cur] + cost;
				if (!vis[i]) {
					vis[i] = 1;
					q.push(i);
				}
				q.push(i);
			}
		}
		vis[cur] = 0;
	}
}

void solve() {
	cin >> n >> m >> k;

	bool flag = false;

	for (int i = 1; i <= k; i++) {
		cin >> row[i] >> col[i];
		flag |= (row[i] == n && col[i] == m);
	}

	if (!flag) {
		k++;
		row[k] = n + 1;
		col[k] = m + 1;
	}

	memset(dis, inf, sizeof(dis));
	memset(vis, 0, sizeof(vis));

	bfs(1);

	if (dis[k] == inf)
		cout << -1;
	else
		cout << dis[k];
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