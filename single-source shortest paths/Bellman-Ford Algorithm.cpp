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
vector <pair<P, int>> Graph;
vector <int> dis(N, inf);
vi par(N);
int n, m;

void bellman_ford(int src) {
	dis[src] = 0;
	while (true) {
		bool flag = false;
		for (int j = 0; j < m; j++) {
			int cost = Graph[j].S;
			int from = Graph[j].F.F;
			int to = Graph[j].F.S;
			if (dis[from] < inf) {
				if (dis[to] > dis[from] + cost) {
					dis[to] = dis[from] + cost;
					par[to] = from;
					flag = true;
				}
			}
		}
		if (!flag)
			break;
	}
}

void shortest_path(int src, int des) {
	if (dis[des] == inf)
		cout << "No Path!!";

	vi path;
	for (int i = des; i != -1; i = par[i]) {
		path.pb(i);
	}
	reverse(all(path));

	for (auto x : path)
		cout << x << " ";
	cout << endl;
}

void solve() {

	par = vi(N, -1);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		Graph.pb({{u, v}, w});
	}
	bellman_ford(1);

	shortest_path(1, n);

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