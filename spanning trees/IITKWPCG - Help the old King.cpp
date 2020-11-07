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
int n, m;

#define node pair <int,P>
vector <node> edges;

int par[N];
void init() {
	REP(i, 1, N)
	par[i] = i;
}

int find(int a) {
	return (a == par[a] ? a : par[a] = find(par[a]));
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

	init();
	edges.clear();

	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		//factors of w;
		w = __builtin_ctzll(w);
		edges.pb({w, {u, v}});
	}
	sort(all(edges));

	// for (auto x : edges)
	// 	cout << x.S.F << " " << x.S.S << " " << x.F << endl;

	int cost = 0;
	for (auto x : edges) {
		int u = x.S.F;
		int v = x.S.S;
		int w = x.F;
		if (find(u) != find(v)) {
			unite(u, v);
			cost += w;
		}
	}
	cout << cost + 1 << endl;// '+1' bcz 1 is also a divisor;

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