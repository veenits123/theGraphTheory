#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

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

const int N = 1e5 + 5;
vi parent(N);
int n, m;

#define node pair<int,P>
vector <node> edges;
vector <node> tree;

void init() {
	REP(i, 1, N)
	parent[i] = i;
}

int find(int n) {
	if (n == parent[n])
		return n;
	return parent[n] = find(parent[n]);
}

void unite(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x != y) {
		if (x < y)
			swap(x, y);
		parent[y] = x;
	}
}

vector <P> Graph[N];
int subsize[N];
int res;

void dfs(int src, int cost, int par) {
	subsize[src] = 1;
	for (auto to : Graph[src]) {
		int next = to.F;
		int c = to.S;
		if (next != par) {
			dfs(next, c, src);
			subsize[src] += subsize[next];
		}
	}
	res = ((n - subsize[src]) * subsize[src] * cost) + res;
}

void solve() {

	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		w = pow(2, w);
		edges.pb({w, {u, v}});
	}
	sort(all(edges));

	for (auto x : edges) {
		int u = x.S.F;
		int v = x.S.S;
		int w = x.F;
		int par_u = find(u);
		int par_v = find(v);
		if (par_u != par_v) {
			unite(par_u, par_v);
			tree.pb({w, {u, v}});
		}
	}
	for (auto x : tree) {
		//cout << x.S.F << " " << x.S.S << " " << x.F << endl;
		int u = x.S.F;
		int v = x.S.S;
		int w = x.F;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	res = 0;
	dfs(1, 0, -1);

	cout << res << endl;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	init();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}

