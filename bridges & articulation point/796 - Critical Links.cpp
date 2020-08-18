#include <bits/stdc++.h>
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
int vis[N];
int timer;
int entry[N];
int low[N];
int n, m;
set <P> ans;

void dfs(int src, int par) {
	vis[src] = 1;
	entry[src] = low[src] = timer;
	timer++;
	for (auto to : Graph[src]) {
		if (to == par)
			continue;
		if (vis[to])
			low[src] = min(low[src], entry[to]);
		else {
			dfs(to, src);
			if (low[to] > entry[src]) {
				ans.insert({src, to});
				//cout << "B " << src << " -> " << to << endl;
			}
			low[src] = min(low[src], low[to]);
		}
	}
	return ;
}

void find_bridges() {
	for (int i = 0; i < n; i++) {
		if (!vis[i])
			dfs(i, -1);
	}
	return ;
}

void solve() {
	while (cin >> n) {

		memset(vis, 0, sizeof(vis));
		memset(low, 0, sizeof(low));
		memset(entry, 0, sizeof(entry));
		memset(Graph, 0, sizeof(Graph));
		timer = 0;
		ans.clear();

		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			string s; cin >> s;
			int t = s[1] - '0';
			while (t--) {
				int u; cin >> u;
				Graph[x].pb(u);
			}
		}
		find_bridges();
		cout << ans.size() << " critical links" << endl;
		//sort(ans.begin(), ans.end());
		for (auto x : ans) {
			cout << x.F << " - " << x.S << endl;
		}
		cout << endl;
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