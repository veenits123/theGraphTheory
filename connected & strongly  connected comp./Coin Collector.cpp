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
vi order;
vi comp(N);
vi scc[N];
vi sum(N);
vi a(N);
int n, m;

void dfs1(int src) {
	vis[src] = true;
	for (int to : Graph[src]) {
		if (!vis[to])
			dfs1(to);
	}
	order.pb(src);
}

void dfs2(int src, int cnt) {
	vis[src] = true;
	comp[src] = cnt;
	for (int to : transpose[src]) {
		if (!vis[to])
			dfs2(to, cnt);
	}
}

void genSCC() {
	REP(i, 1, n) {
		for (int x : Graph[i]) {
			if (comp[i] != comp[x]) {
				scc[comp[i]].pb(comp[x]);
			}
		}
	}
}

vi temp(N);

void solve() {

	vis.assign(N, false);
	order.clear();
	comp.assign(N, -1);

	cin >> n >> m;
	REP(i, 1, n)
	cin >> a[i];

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
	vi nodes;
	for (auto x : order) {
		if (!vis[x]) {
			dfs2(x, cnt);
			nodes.pb(cnt);
			cnt++;
		}
	}

	REP(i, 1, n) {
		//cout << comp[i] << " " << i << endl;
		sum[comp[i]] += a[i];
	}

	genSCC();

	int ans = 0;
	reverse(all(nodes));

	for (int i : nodes) {
		for (int x : scc[i]) {
			//cout << temp[i] << " " << temp[x] << endl;
			temp[i] = max(temp[i], temp[x]);
		}
		temp[i] += sum[i];
		//cout << i<<" "<<temp[i] << endl;
		ans = max(ans, temp[i]);
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}