#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 2e3 + 5;
vector <int> Graph[N];
bool visited[N];
vector <int> dis(N, 0);
int n, m;

void bfs(int src) {
	queue <int> q;
	q.push(src);
	visited[src] = true;
	dis[src] = 0;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0; i < Graph[temp].size(); i++) {
			int to = Graph[temp][i];
			if (!visited[to]) {
				q.push(to);
				visited[to] = true;
				dis[to] = dis[temp] + 1;
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char x; cin >> x;
			if (x == '#') {
				Graph[i].pb(j + n);
				Graph[j + n].pb(i);
			}
		}
	}
	dis[1] = -1;
	bfs(n);
	cout << dis[1] << endl;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--){}
	solve();


	return 0;
}