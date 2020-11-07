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

const int N = 3e3 + 5;
const int inf = 1e18;
vector < pair<P, int> > edges;
vi dis(N, inf);
vi cycle(N);
int ind;
int n, m;

void bellman() {
	dis[1] = 0;
	REP(i, 1, n - 1) {
		for (auto x : edges) {
			int from = x.F.F;
			int to = x.F.S;
			int cost = x.S;
			if (dis[from] < inf) {
				if (dis[to] > dis[from] + cost) {
					dis[to] = dis[from] + cost;
				}
			}
		}
	}
	for (auto x : edges) {
		int from = x.F.F;
		int to = x.F.S;
		int cost = x.S;
		if (dis[from] < inf) {
			if (dis[to] > dis[from] + cost) {
				cycle[to] = 1;
			}
		}
	}
	REP(i, 1, n - 1) {
		for (auto x : edges) {
			int from = x.F.F;
			int to = x.F.S;
			int cost = x.S;
			if (cycle[from] == 1) {
				cycle[to] = 1;
			}
		}
	}
}

int ans(int x) {
	if (cycle[x])
		return -1;
	return -dis[x];
}

void solve() {

	dis = vi(N, inf);

	cin >> n >> m;
	REP(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		edges.pb({{u, v}, -w});
	}
	ind = -1;
	bellman();
	//cout << ind << endl;

	// REP(i, 1, n)
	// cout << dis[i] << " ";
	cout << ans(n);

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