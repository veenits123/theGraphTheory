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

const int N = 1e3 + 5;
int par[N];

#define node pair<int,P>
vector <node> edges;

void init() {
	REP(i, 1, N)
	par[i] = i;
}

int find(int a) {
	if (a == par[a])
		return a;
	return par[a] = find(par[a]);
}

void unite(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x != y) {
		if (x < y)
			swap(x, y);
		par[y] = x;
	}
}

void solve() {

	map <int, int> sub;
	int n; cin >> n;
	int vis[n + 1];
	REP(i, 1, n) {
		int x; cin >> x;
		vis[i] = 0;
	}
	int m; cin >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		sub[v]++;
		edges.pb({w, {u, v}});
	}
	int c = 0;
	REP(i, 1, n) {
		if (sub[i] == 0)
			c++;
		if (c > 1) {
			cout << -1 << endl;
			return ;
		}
	}
	sort(all(edges));

	// for (auto x : edges)
	// 	cout << x.S.F << " " << x.S.S << " " << x.F << endl;

	int ans = 0;
	for (auto x : edges) {
		int u = x.S.F;
		int v = x.S.S;
		int w = x.F;
		if (!vis[v])
			if (find(u) != find(v)) {
				ans += w;
				unite(v, u);
				vis[v] = 1;
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

	init();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}