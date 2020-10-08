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
const int mod = 1e9;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e5 + 5;

#define node pair<int,P>
vector <node> edges;

int par[N];
int sz[N];

void init() {
	REP(i, 1, N) {
		par[i] = i;
		sz[i] = 1;
	}
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
		if (sz[x] < sz[y])
			swap(x, y);
		par[y] = x;
		sz[x] += sz[y];
		sz[y] = 0;
	}
}

int cum_sum[N];

void solve() {

	int n, m; cin >> n >> m;

	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		edges.pb({w, {u, v}});
	}
	sort(all(edges));

	REP(i, 0, sz(edges) - 1) {
		int w = edges[i].F;
		cum_sum[i] = w + (i > 0 ? cum_sum[i - 1] : 0);
	}
	int ans = 0;

	REV(i, sz(edges) - 1, 0) {
		int u = edges[i].S.F;
		int v = edges[i].S.S;

		int par_u = find(u);
		int par_v = find(v);
		if (par_u != par_v) {
			int temp = sz[par_u] * sz[par_v] % mod;
			ans = (ans % mod + temp * cum_sum[i] % mod) % mod;
			
			unite(par_u, par_v);
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