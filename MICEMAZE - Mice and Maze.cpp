#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int i, j, n, m;
	cin >> n;
	int s; cin >> s;
	int tm; cin >> tm;
	cin >> m;
	vector<P> gr[n + 1];
	for (i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[y].pb({x, w});
		//gr[y].push_back({x,w});
	}
	int mindis[n + 1], vis[n + 1];
	for (i = 0 ; i <= n ; i++) {
		mindis[i] = INT_MAX;
		vis[i] = 0;
	}
	//int source;
	//cin>>source;

	priority_queue<P, vector<P>, greater<P> > Q;

	Q.push({0, s});

	while (!Q.empty()) {
		P tp = Q.top(); // smallest dis till now
		Q.pop();
		int cur_node = tp.S;
		int dis = tp.F;
		// if included then dont visit again
		if (vis[cur_node] == 1) continue;
		// otherwise visit the node and include in the shortest path
		vis[cur_node] = 1;
		mindis[cur_node] = dis;

		for (auto x : gr[cur_node]) {
			int adjacent_node = x.F;
			int weight_of_ad_node = x.S;
			Q.push({mindis[cur_node] + weight_of_ad_node, adjacent_node});
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++) {
		//cout<<i<<" "<<mindis[i]<<'\n';
		if (mindis[i] <= tm)
			ans++;
	}
	cout << ans << endl;




	return 0;
}