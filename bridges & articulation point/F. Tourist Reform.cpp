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

const int N = 4e5 + 5;
vector <P> Graph[N];//{node, seq. of input of edges};
int entry[N];
int low[N];
int timer;

stack <int> st;
int cnt;
int scc[N];
int minri[N];

int n, m;

//tarjan's algorithm is used to find strongly connected comp. i.e. scc;
void tarjan(int src, int par) {

	entry[src] = low[src] = timer++;
	st.push(src);

	for (auto to : Graph[src]) {
		int child = to.F;

		if (child == par)
			continue;

		if (!entry[child]) {
			tarjan(child, src);
			low[src] = min(low[src], low[child]);
		}

		else {//back edge;
			low[src] = min(low[src], entry[child]);
		}
	}

	//strongly connected components;
	if (low[src] == entry[src]) {
		cnt++;//no. of connected comp;
		while (!st.empty()) {
			int temp = st.top();
			st.pop();

			scc[temp] = cnt;

			minri[cnt]++;//size of connected components;

			if (temp == src)
				break;
		}
	}
}

P ans[N];
int vis[N];//edges visited or not ??;

void dfs(int src, int par) {
	for (auto to : Graph[src]) {
		int no = to.S;//input seq of edges;
		int child = to.F;
		if (child != par && !vis[no]) {//edge oriented yet or not ??

			vis[no] = 1;

			if (scc[src] != scc[child]) {//the bridge;
				ans[no].F = child;
				ans[no].S = src;
			}
			else {
				ans[no].F = src;
				ans[no].S = child;
			}
			dfs(child, src);
		}
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb({v, i});
		Graph[v].pb({u, i});
	}

	tarjan(1, -1);

	int pos = 1;
	for (int i = 1; i <= n; i++) {
		if (minri[scc[i]] > minri[scc[pos]])
			pos = i;
	}
	dfs(pos, -1);

	cout << minri[scc[pos]] << endl;

	for (int i = 1; i <= m; i++) {
		cout << ans[i].F << " " << ans[i].S << endl;
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