#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
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
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod (int)1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e6 + 5;
vi Graph[N];
vi vis(N);
vi dis(N);
int f, s, g, u, d;

int bfs(int src, int des) {
	queue <int> q;
	q.push(src);
	vis[src] = 1;
	dis[src] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == des) {
			return dis[cur];
		}
		for (int to : Graph[cur]) {
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
				dis[to] = dis[cur] + 1;
			}
		}
	}
	return -1;
}

void solve() {

	cin >> f >> s >> g >> u >> d;
	for (int i = 1; i + u <= f; i++) {
		Graph[i].pb(i + u);
	}
	for (int i = f; i - d >= 1; i--) {
		Graph[i].pb(i - d);
	}
	int ans = bfs(s, g);
	if (ans == -1)
		cout << "use the stairs";
	else
		cout << ans;

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