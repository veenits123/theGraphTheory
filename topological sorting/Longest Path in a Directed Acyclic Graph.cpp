#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;
vector <int> Graph[N];
vector <int> ans;
vector <int> indeg;
vector <int> dis, par;
int n, m;
const int minf = -1e9;

typedef vector <int> vi;

void kahn(int no) {
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0)//starting node;
			q.push(i);
	}
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		ans.pb(temp);//adding to topo-sort array i.e. ans;
		for (auto to : Graph[temp]) {
			indeg[to]--;
			if (indeg[to] == 0)
				q.push(to);
		}
	}
}

void longest_path(int src) {
	dis[src] = 0;
	for (auto x : ans) {
		for (auto to : Graph[x]) {
			if (dis[x] != minf)
				if (dis[to] < dis[x] + 1) {
					dis[to] = dis[x] + 1;
					par[to] = x;
				}
		}
	}
}

void solve() {
	ans.clear();
	indeg = vi(N, 0);
	dis = vi(N, minf);
	par = vi(N, -1);

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		//Graph[v].pb(u);
		indeg[v]++;
	}
	kahn(n);

	// for (auto x : ans)
	// 	cout << x << " ";

	longest_path(1);
	if (dis[n] != minf) {
		cout << dis[n] + 1 << endl;
		vector <int> path;
		for (int i = n; i != -1; i = par[i]) {
			path.pb(i);
		}
		reverse(path.begin(), path.end());
		for (auto x : path)
			cout << x << " ";
		cout << endl;
	}
	else
		cout << "IMPOSSIBLE" << endl;

	// for (int i = 1; i <= n; i++)
	// 	cout << dis[i] << " ";
	// cout << endl;
	// for (int i = n; i != -1; i = par[i]) {
	// 	cout << i << " ";
	// }

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}