#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 1e5 + 5;
vector <int> Graph[N];
int vis[N];
int out[N];
int entry[N];
int timer = 1;
vector <int> components;
int n, m;

void dfs(int src) {
	entry[src] = timer++;
	vis[src] = 1;
	components.pb(src);
	//cout << src << " ";
	for (auto to : Graph[src]) {
		if (!vis[to]) {
			dfs(to);
		}
	}
	out[src] = timer++;
	//cout << src << " "<<"{"<<entry[src]<<", "<<out[src]<<"}"<<endl;
}

void connected_comp() {
	vector <vector<int>> v;
	for (int i = 1; i <= n; i++) {
		components.clear();
		if (!vis[i]) {
			dfs(i);
			v.pb(components);
		}
	}
	cout << v.size() << endl;
	// for (auto x : v) {
	// 	for (auto to : x) {
	// 		cout << to << " ";
	// 	}
	// 	cout << endl;
	// }
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	cin >> n >> m; //n=nodes, m=edges;
	while (m--) {
		int x, y; cin >> x >> y;
		Graph[x].pb(y);
		Graph[y].pb(x);
	}
	//dfs(5);
	connected_comp();

	return 0;
}