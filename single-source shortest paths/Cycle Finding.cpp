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
const int inf = 1e18;
vector < pair<P, int> > edges;
vi dis(N, inf);
vi par(N);
int ind;
int n, m;

void bellman() {
	dis[3] = 0;
	REP(i, 1, n) {
		ind = -1;
		for (int j = 0; j < m; j++) {
			int from = edges[j].F.F;
			int to = edges[j].F.S;
			int cost = edges[j].S;
			//cout << from << " " << to << " " << dis[from] << endl;
			if (dis[from] < inf) {
				//cout << from << " " << to << endl;
				if (dis[to] > dis[from] + cost) {
					dis[to] = max(-inf, dis[from] + cost);
					par[to] = from;
					ind = to;
				}
			}
		}
	}
}

void cycle() {
	if (ind == -1)
		cout << "NO" << endl;
	else {
		int x = ind;
		REP(i, 1, n) {
			x = par[x];
		}
		vi path;
		for (int i = x;; i = par[i]) {
			path.pb(i);
			if (i == x && sz(path) > 1)
				break;
		}
		reverse(all(path));
		cout << "YES" << endl;
		for (auto x : path)
			cout << x << " ";
		cout << endl;
	}
}

void solve() {

	dis = vi(N, inf);

	cin >> n >> m;
	REP(i, 1, m) {
		int u, v, w; cin >> u >> v >> w;
		edges.pb({{u, v}, w});
	}
	// for (auto x : edges) {
	// 	cout << x.F.F << " " << x.F.S << " " << x.S << endl;
	// }
	ind = -1;
	bellman();
	//REP(i, 1, n)
	//cout << dis[i] << " ";
	cycle();

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