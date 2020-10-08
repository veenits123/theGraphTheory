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
vector <P> Graph[N], transpose[N];
vi fwd(N), rev(N);
int n, m;

void dijkstra(int src) {
	priority_queue <P, vector<P>, greater<P> > q;
	q.push({0, src});
	fwd[src] = 0;
	while (!q.empty()) {
		int cost = q.top().F;
		int cur = q.top().S;
		q.pop();
		if (fwd[cur] < cost)
			continue;
		for (auto to : Graph[cur]) {
			int w = to.S;
			int node = to.F;
			if (fwd[node] > cost + w) {
				fwd[node] = cost + w;
				q.push({fwd[node], node});
			}
		}
	}
}

void dijkstra1(int src) {
	priority_queue <P, vector<P>, greater<P> > q;
	q.push({0, src});
	rev[src] = 0;
	while (!q.empty()) {
		int cost = q.top().F;
		int cur = q.top().S;
		q.pop();
		if (rev[cur] < cost)
			continue;
		for (auto to : transpose[cur]) {
			int w = to.S;
			int node = to.F;
			if (rev[node] > cost + w) {
				rev[node] = cost + w;
				q.push({rev[node], node});
			}
		}
	}
}

void solve() {

	fwd.assign(N, 1e18);
	rev.assign(N, 1e18);

	cin >> n >> m;
	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		transpose[v].pb({u, w});
	}
	dijkstra(1);
	dijkstra1(n);

	int ans = 1e18;

	REP(i, 1, n) {
		for (auto x : Graph[i]) {
			//cout << fwd[i] << " " << rev[x.F] << " " << x.S / 2 << endl;
			ans = min(ans, fwd[i] + rev[x.F] + x.S / 2);
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}