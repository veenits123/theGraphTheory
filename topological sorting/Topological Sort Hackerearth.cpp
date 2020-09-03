#include <iostream>
#include <vector>
#include <queue>
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
vector <int> Graph[N];
vector <int> ans;
vector <int> indeg;
int n, m;

typedef vector <int> vi;

void kahn(int n) {
	priority_queue <int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int temp = q.top();
		q.pop();
		ans.pb(temp);
		for (auto to : Graph[temp]) {
			indeg[to]--;
			if (indeg[to] == 0)
				q.push(to);
		}
	}
	for (auto x : ans)
		cout << x << " ";
	cout << endl;
}

void solve() {
	indeg = vi(N, 0);
	ans.clear();

	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		Graph[u].pb(v);
		indeg[v]++;
	}
	kahn(n);

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