#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cstring>
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
vi vis(N);
int a[N];
vi order, comp;
int n;

void dfs1(int src) {
	vis[src] = 1;
	for (auto to : Graph[src])
		if (!vis[to])
			dfs1(to);
	order.pb(src);
}

void dfs2(int src) {
	vis[src] = 1;
	comp.pb(src);
	for (auto to : transpose[src])
		if (!vis[to])
			dfs2(to);
}

void solve() {

	order.clear();
	vis.assign(n + 1, 0);

	cin >> n;

	REP(i, 0, n - 1) {
		//vis[i] = 0;
		Graph[i].clear();
		transpose[i].clear();

		cin >> a[i];
	}
	REP(i, 0, n - 1) {
		int u = i;
		int v = (i + a[i] + 1) % n;
		Graph[u].pb(v);
		transpose[v].pb(u);
	}

	REP(i, 0, n - 1) {
		if (!vis[i])
			dfs1(i);
		// for (auto x : Graph[i])
		// 	cout << x << " ";
		// cout << endl;
	}
	reverse(all(order));

	// for (auto x : order)
	// 	cout << x << " ";
	// cout << endl;

	// REP(i, 0, n)
	// vis[i] = 0;
	vis.assign(n + 1, 0);

	int ans = 0;
	for (auto x : order) {
		if (!vis[x]) {
			comp.clear();
			dfs2(x);
			if (sz(comp) == 1 && comp[0] != Graph[comp[0]][0])
				continue;
			ans += sz(comp);
		}

	}
	cout << ans << endl;

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