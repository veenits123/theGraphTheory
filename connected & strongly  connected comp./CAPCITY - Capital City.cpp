#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e5 + 5;
vi Graph[N], transpose[N];
vb vis(N);
vi comp(N);
vi order;
vi indegree(N);
int n, m;

void dfs1(int src) {
	vis[src] = true;
	for (int to : Graph[src])
		if (!vis[to])
			dfs1(to);
	order.pb(src);
}

void dfs2(int src, int cnt) {
	vis[src]=true;
	comp[src] = cnt;
	for (int to : transpose[src])
		if (!vis[to])
			dfs2(to, cnt);
}

void solve() {

	vis.assign(N, false);
	indegree.assign(N, 0);
	comp.assign(N, 0);
	order.clear();

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		transpose[v].pb(u);
	}
	REP(i, 1, n)
	if (!vis[i])
		dfs1(i);
	reverse(all(order));

	vis.assign(N, false);

	int cnt = 1;
	for (int x : order)
		if (!vis[x])
			dfs2(x, cnt), cnt++;

	REP(i, 1, n) {
		for (int to : Graph[i]) {
			if (comp[i] != comp[to]) {
				indegree[comp[i]]++;
			}
		}
	}

	int flag = 0, root = -1;
	REP(i, 1, cnt - 1)
	if (!indegree[i])
		flag++, root = i;

	if (flag != 1) {
		cout << 0 << endl;
		return ;
	}

	vi ans;
	REP(i, 1, n) {
		if (comp[i] == root) {
			ans.pb(i);
		}
	}
	cout << ans.size() << endl;
	for (int x : ans)
		cout << x << " ";

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