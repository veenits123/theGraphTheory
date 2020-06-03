#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long int
#define pb push_back
#define endl '\n'

const int N = 1e6 + 5;
vector <int> Graph[N];
bool visited[N];
int strength[N], dis[N];

void bfs(int src) {
	queue <int> q;
	q.push(src);
	visited[src] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		//cout << temp.name << " ";
		for (int i = 0; i < Graph[temp].size(); i++) {
			int to = Graph[temp][i];
			if (!visited[to]) {
				q.push(to);
			}
			visited[to] = true;
		
			if (strength[temp] < strength[to] - 1 && dis[temp] == -1) {
				strength[temp] = strength[to] - 1;
			}
			if (dis[to] == -1) {
				strength[to] = max(strength[to], strength[temp] - 1);
			}
		}

	}
	//cout << endl;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--) {

		int n, r, m; cin >> n >> r >> m;
		for (int i = 0; i <= n; i++) {
			visited[i] = false;
			Graph[i].clear();
			strength[i] = -1;
			dis[i] = -1;
		}
		while (r--) {
			int u, v; cin >> u >> v;
			Graph[u].pb(v);
			Graph[v].pb(u);
		}
		bool ans = true;
		while (m--) {
			int u, x; cin >> u >> x;
			strength[u] = x;
			dis[u] = x;
		}
		bfs(1);
		for (int i = 1; i <= n; i++) {
			if (strength[i] < 0) {
				ans = false;
				break;
			}
		}
		if (ans)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}


	return 0;
}