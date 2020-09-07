#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e4 + 5;
vector <int> Graph[N];
bool visited[N];
vector <int> dis(N);

void bfs(int src) {
	queue <int> q;
	q.push(src);
	visited[src] = true;
	dis[src] = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0; i < Graph[temp].size(); i++) {
			int to = Graph[temp][i];
			if (!visited[to]) {
				q.push(to);
				visited[to] = true;
				dis[to] = dis[temp] + 1;
			}
		}
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

	int t; cin >> t; while (t--) {

		int n, e; cin >> n >> e;
		for (int i = 0; i <= n; i++)
			Graph[i].clear();
		for (int i = 0; i < N; i++)
			visited[i] = 0;

		for (int i = 0; i < e; i++) {
			int x, y; cin >> x >> y;
			Graph[x].pb(y);
			Graph[y].pb(x);
		}
		bfs(1);
		cout << dis[n] << endl;
	}

	return 0;
}