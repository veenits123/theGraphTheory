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

const int N = 1e2 + 5;
vector <int> Graph[N];
vector <int> transpose[N];
int vis[N];
vector <int> ord;
int n;

void dfs1(int src) {
	vis[src] = 1;
	for (auto to : Graph[src]) {
		if (!vis[to])
			dfs1(to);
	}
	ord.pb(src);
}

void dfs2(int src) {
	vis[src] = 1;
	for (auto to : transpose[src]) {
		if (!vis[to])
			dfs2(to);
	}
}

void solve() {
	memset(vis, 0, sizeof(vis));
	memset(Graph, 0, sizeof(Graph));
	memset(transpose, 0, sizeof(transpose));
	ord.clear();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char x; cin >> x;
			if (x == 'Y') {
				Graph[i].pb(j);
				transpose[j].pb(i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs1(i);
	reverse(ord.begin(), ord.end());
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (auto x : ord)
		if (!vis[x]) {
			dfs2(x);
			cnt++;
		}
	cout << cnt << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}