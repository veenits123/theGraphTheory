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

const int N = 1e5 + 5;
vector <int> Graph[N];
bool visited[N];
vector <int> dis(N);
int n;

void bfs(int src) {
	queue <int> q;
	q.push(src);
	visited[src] = true;
	dis[src] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		//cout << temp << " ";
		for (int i = 0; i < Graph[temp].size(); i++) {
			int to = Graph[temp][i];
			if (!visited[to]) {
				q.push(to);
				visited[to] = true;
				dis[to] = dis[temp] + 1;
			}
		}
	}
	//cout << endl;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	int x; cin >> x;
	bfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] == x)
			ans++;
	}
	cout << ans << endl;

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

	//int t;cin>>t;while(t--){}

	solve();

	return 0;
}