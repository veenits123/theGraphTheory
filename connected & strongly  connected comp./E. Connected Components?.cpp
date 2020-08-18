#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
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

const int N = 2e5 + 5;
set <int> Graph[N];
set <int> unvis;
int n, m;
int ans[N];
int cnt;

void dfs(int src) {
	unvis.erase(src);
	//cout<<src<<" ";
	ans[cnt]++;
	int temp = 0;
	while (1) {
		auto it = unvis.upper_bound(temp);
		if (it == unvis.end())
			break;
		temp = *it;

		if (Graph[src].count(temp))
			continue;
		//cout<<temp<<" ";
		dfs(temp);
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		Graph[u].insert(v);
		Graph[v].insert(u);
	}
	for (int i = 1; i <= n; i++)
		unvis.insert(i);
	for (int i = 1; i <= n; i++) {
		if (unvis.count(i)) {
			cnt++;
			dfs(i);
			//cout<<i<<" ";
		}
	}
	cout << cnt << endl;
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << " ";
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