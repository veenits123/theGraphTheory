#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 3e5 + 5;
set <int> forbid[N];
set <int> node;
int vis[N];
int n, m, k;
bool flag;

void bfs(int src) {
	queue <int> q;
	q.push(src);
	vis[src] = 1;

	vector <int> temp;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto to : node) {

			if (!forbid[cur].count(to)) {

				vis[to] = 1;
				q.push(to);
				temp.pb(to);
			}
		}
		for (auto x : temp) {
			node.erase(x);
		}

		temp.clear();

		if (!forbid[cur].count(1)) {
			flag = true;
		}
	}
}

void solve() {
	cin >> n >> m >> k;
	int one = n - 1;
	while (m--) {
		int x, y; cin >> x >> y;
		forbid[x].insert(y);
		forbid[y].insert(x);
		if (x == 1 || y == 1)
			one--;
	}
	if (one < k) {
		cout << "impossible";
		return ;
	}

	for (int i = 2; i <= n; i++) {
		node.insert(i);
	}
	int count = 0;

	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			count++;
			bfs(i);
			if (!flag) {
				cout << "impossible";
				return ;
			}
			flag = false;
		}
	}
	if (count > k) {
		cout << "impossible";
		return ;
	}

	cout << "possible";
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