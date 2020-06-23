#include <iostream>
#include <vector>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e2 + 5;
vector <P> Graph[N];
int vis[N];
int n;
int ans;

int dfs(int src) {
	vis[src] = 1;
	int temp = 0;
	//cout<<src<<" ";
	for (auto to : Graph[src]) {
		int child = to.F;
		int cost = to.S;
		if (!vis[child]) {
			int cur = dfs(child);
			//cout<<cur<<" "<<cost<<endl;
			cur += cost;
			temp = max(temp, cur);
		}
	}
	return temp;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w;
		Graph[u].pb({v, w});
		Graph[v].pb({u, w});
	}
	ans = dfs(0);
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