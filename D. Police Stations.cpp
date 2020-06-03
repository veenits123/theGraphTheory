#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>

using namespace std;

#define int long long
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 3e5 + 5;
vector <int> Graph[N];
int vis[N];
vector <int> pol;
int n, k, d;
map <P, int> road;
set <int> s;

void bfs() {
	queue <int> q;
	for (auto x : pol) {
		q.push(x);
		vis[x] = 1;
	}
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (auto to : Graph[temp]) {
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
				s.erase(road[ {temp, to}]);
			}
		}
	}
}

void solve() {
	cin >> n >> k >> d;
	while (k--) {
		int x; cin >> x;
		pol.pb(x);
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
		s.insert(i);
		road[ {u, v}] = i;
		road[ {v, u}] = i;
	}
	memset(vis, 0, sizeof(vis));
	bfs();
	cout << s.size() << endl;
	for (auto x : s)
		cout << x << " ";
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

	solve();

	return 0;
}