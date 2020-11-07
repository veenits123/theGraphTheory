#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <stack>
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
vb vis(N);
int low[N], entry[N];
int timer;
int n, m;
stack <int> st;
vector <vi> comp;

void dfs(int src) {

	st.push(src);
	vis[src] = true;
	low[src] = entry[src] = timer++;

	for (auto to : Graph[src]) {
		if (vis[to]) {
			low[src] = min(low[src], entry[to]);
		}
		else if (entry[to] == -1) {
			dfs(to);
			low[src] = min(low[src], low[to]);
		}
	}

	int w = -1;
	if (low[src] == entry[src]) {
		vi temp;
		while (st.top() != src) {
			w = st.top();
			temp.pb(w);
			vis[w] = false;
			st.pop();
		}
		w = st.top();
		temp.pb(w);
		vis[w] = false;
		st.pop();

		comp.pb(temp);
		temp.clear();
	}
}

int ans[N];

void solve() {

	vis.assign(N, false);
	timer = 1;
	fill(low, low + N, -1);
	fill(entry, entry + N, -1);

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
	}

	REP(i, 1, n) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	if (sz(comp) == 1)
		cout << "YES" << endl;
	else {
		cout << "NO" << endl;
		cout << comp[0][0] << " " << comp[1][0] << endl;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}