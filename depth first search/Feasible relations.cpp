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
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod 1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e6 + 5;
vi Graph[N];
vi vis;
vi comp;
bool flag;
int cnt;
vector <P> unequal;
int n, m;

void dfs(int src) {
	vis[src] = 1;
	comp[src] = cnt;
	for (int to : Graph[src])
		if (!vis[to])
			dfs(to);
}

void connected_comp() {
	vis.assign(N, 0);
	comp.assign(N, 0);
	flag = true;
	cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			cnt++;
		}
	}
	for (auto x : unequal) {
		if (comp[x.F] == comp[x.S]) {
			flag = false;
			break;
		}
	}
}

void solve() {

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		Graph[i].clear();
	unequal.clear();

	while (m--) {
		int a, b;
		string sign; cin >> a >> sign >> b;
		if (sign == "=") {
			Graph[a].pb(b);
			Graph[b].pb(a);
		}
		else {
			unequal.pb({a, b});
		}
	}
	connected_comp();
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

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