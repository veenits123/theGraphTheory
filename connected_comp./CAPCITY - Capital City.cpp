#include <iostream>
#include <vector>
#include <cstring>
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
vector <int> transpose[N];
int comp[N];
int vis[N];
int indeg[N];
vector <int> out;
int n, m;

void dfs1(int src) {
	vis[src] = 1;
	//cout<<src<<" ";
	for (auto to : Graph[src]) {
		if (!vis[to]) {
			dfs1(to);
		}
	}
	out.pb(src);
}

void dfs2(int src, int cnt) {
	comp[src] = cnt;
	for (auto to : transpose[src]) {
		if (!comp[to]) {
			comp[to] = cnt;
			dfs2(to, cnt);
		}
	}
}

void in_degree() {
	for (int i = 1; i <= n; i++) {
		for (auto to : Graph[i]) {
			if (comp[i] != comp[to]) {
				indeg[comp[to]]++;
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[v].pb(u);
		transpose[u].pb(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs1(i);
		}
	}
	reverse(out.begin(), out.end());

	int cc = 1;
	for (auto x : out) {
		if (!comp[x]) {
			dfs2(x, cc);
			cc++;
		}
	}
	in_degree();

	int nodes = 0, par;
	for (int i = 1; i <= cc - 1; i++) {
		if (!indeg[i]) {
			nodes++;
			par = i;
		}
	}
	if (nodes == 1) {
		int cnt = 0;
		vector <int> ans;
		for (int i = 1; i <= n; i++) {
			if (comp[i] == par) {
				ans.pb(i);
				cnt++;
			}
		}
		cout << cnt << endl;
		sort(ans.begin(), ans.end());
		for (auto x : ans)
			cout << x << " ";
		cout << endl;
	}
	else {
		cout << 0 << endl;
	}

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