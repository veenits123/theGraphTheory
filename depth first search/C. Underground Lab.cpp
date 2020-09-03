#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 2e5 + 5;
int vis[N];
vector <int> Graph[N];
int n, m, k;
queue <int> q;

void dfs(int src) {
	vis[src] = 1;
	//cout<<src<<" ";
	q.push(src);
	for (auto to : Graph[src]) {
		if (!vis[to]) {
			dfs(to);
			q.push(src);//visiting again;
		}
	}
}

void solve() {
	cin >> n >> m >> k;
	while (m--) {
		int x, y; cin >> x >> y;
		Graph[x].pb(y);
		Graph[y].pb(x);
	}
	dfs(1);

	for (int i = 0; i < k; i++) {

		int total = min((int)q.size(), (2 * n + k - 1) / k);

		cout << max((int)1, total) << " ";

		if (!total) {
			cout << 1 << " ";
		}

		while (total--) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}