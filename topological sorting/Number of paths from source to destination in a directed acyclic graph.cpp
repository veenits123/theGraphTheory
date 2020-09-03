#include <iostream>
#include <vector>
#include <queue>
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

const int N = 1e5 + 5;
vector <int> Graph[N];
vector <int> ans;
vector <int> indeg;
int n, m;

typedef vector <int> vi;

void kahn() {
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0)//starting node;
			q.push(i);
	}
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		ans.pb(temp);//adding to topo-sort array i.e. ans;
		for (auto to : Graph[temp]) {
			indeg[to]--;
			if (indeg[to] == 0)
				q.push(to);
		}
	}
}

int no_of_paths(int src, int des) {
	vector <int> dp(N, 0);
	dp[des] = 1; //only one way from des to des ;)

	//reverse topo-sort array i.e. ans;
	//why ??
	//bcz : in order to evaluate f(u) for each u just once,
	// evaluate f(v) for all v that can be visited from u before evaluating f(u);
	//f(u) : the number of ways from node u to destination

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		for (auto x : Graph[ans[i]]) {
			dp[ans[i]] += dp[x];
		}
	}
	return dp[src];
}

void solve() {
	ans.clear();
	indeg = vi(N, 0);

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		indeg[v]++;
	}
	kahn();

	cout << no_of_paths(1, n) << endl;

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