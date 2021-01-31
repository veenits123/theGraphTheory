#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cstring>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod 1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 2e5 + 5;
vector <int> Graph[N];
vector <int> vis;
vector <int> color;
vector <P> edge;
int n, m;
bool flag;

void bfs(int src, int col) {
	queue <int> q;
	q.push(src);
	vis[src] = 1;
	color[src] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (auto to : Graph[temp]) {
			if (!vis[to]) {
				q.push(to);
				vis[to] = 1;
				color[to] = color[temp] ^ 1;
			}
			else {
				if (color[temp] == color[to])
					flag = false;
			}
		}
	}
}

typedef vector <int> vii;

void solve() {

	color = vii(N, -1);
	vis = vii(N, 0);
	flag = true;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		Graph[v].pb(u);
		edge.pb({u, v});
	}
	bfs(1, 1);
	if (!flag) {
		cout << "NO" << endl;
		return ;
	}

	cout << "YES" << endl;
	string ans = "";
	for (int i = 0; i < m; i++) {
		if (color[edge[i].F] > color[edge[i].S])
			ans += '1';
		else
			ans += '0';
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