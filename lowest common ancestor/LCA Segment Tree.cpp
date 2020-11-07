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
vi Graph[N];
vi euler_tour;
vb vis(N);
vi tree(4 * N);
vi level(N);
vi occur(N);
int n;

void dfs(int src, int h) {
	vis[src] = true;
	euler_tour.pb(src);
	level[src] = h;
	occur[src] = sz(euler_tour) - 1;

	for (int to : Graph[src]) {
		if (!vis[to]) {
			dfs(to, h + 1);
			euler_tour.pb(src);
		}
	}
}

void build(int pos, int st, int en) {
	if (st == en) {
		tree[pos] = euler_tour[st];
		return ;
	}
	int mid = (st + en) >> 1;

	build(pos << 1, st, mid);
	build(pos << 1 | 1, mid + 1, en);

	int left = tree[pos << 1];
	int right = tree[pos << 1 | 1];

	tree[pos] = (level[left] < level[right]) ? left : right;
}

int query(int pos, int st, int en, int l, int r) {
	if (l > en || st > r)
		return -1;
	if (st >= l && en <= r)
		return tree[pos];
	int mid = (st + en) >> 1;

	int left = query(pos << 1, st, mid, l, r);
	int right = query(pos << 1 | 1, mid + 1, en, l, r);

	if (left == -1)
		return right;
	if (right == -1)
		return left;

	return (level[left] < level[right] ? left : right);
}

int find_lca(int a, int b) {
	int left = occur[a];
	int right = occur[b];
	if (left > right)
		swap(left, right);
	return query(1, 0, sz(euler_tour) - 1, left, right);
}

void solve() {

	cin >> n;

	euler_tour.reserve(2 * N);
	vis = vb(N, false);
	tree.resize(4 * N);
	level = vi(N, 0);
	occur.resize(N);

	REP(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
	}
	dfs(1, 0);
	build(1, 0, sz(euler_tour) - 1);

	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		cout << find_lca(u, v) << endl;
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

	//int t; cin >> t; while (t--)
	solve();

	return 0;
}