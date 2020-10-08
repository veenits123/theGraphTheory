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
vi vis(N);
vi order, comp;
int n, m;

void dfs(int src) {
	vis[src] = 1;
	for (auto to : Graph[src]) {
		if (!vis[to])
			dfs(to);
	}
	order.pb(src);
}

void dfs1(int src) {
	vis[src] = 1;
	//comp.pb(src);
	for (auto to : transpose[src])
		if (!vis[to])
			dfs1(to);
}

void solve() {

	vis.assign(N, 0);
	order.clear();
	//comp.clear();

	cin >> n >> m;
	REP(i, 0, n)
	Graph[i].clear(), transpose[i].clear();

	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		transpose[v].pb(u);
	}
	REP(i, 1, n)
	if (!vis[i])
		dfs(i);

	reverse(all(order));

	vis.assign(N, 0);

	int col = 0;
	int a = -1, b = -1;
	for (auto x : order) {
		if (!vis[x]) {
			col++;
			//comp.clear();
			dfs1(x);
			if (col > 1) {
				a = x;
				b = order[0];
				break;
			}
		}
	}
	if (col == 1)
		cout << "YES" << endl;
	else {
		cout << "NO" << endl;
		cout << a << " " << b << endl;
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