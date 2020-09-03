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

const int N = 1e5 + 5;
vector <int> Graph[N];
bool visited[N] = {false};
vector <int> dis(N), h(N), v(N);

int s, f, r;

void bfs(int src) {
	queue <int> q;
	q.push(src);
	dis[src] = 0;
	visited[src] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		//cout << temp << " ";
		for (int i = 0; i < Graph[temp].size(); i++) {
			int to = Graph[temp][i];
			if (!visited[to]) {
				q.push(to);
				visited[to] = true;
				int b = dis[temp] + 1;
				if (dis[to] == -1)
					dis[to] = b;
			}
		}
	}
	//cout << endl;
}

void bfs_2(int src) {
	queue <int> q;
	q.push(src);
	h[src] = dis[src];
	v[src] = 0;
	visited[src] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		//cout << temp << " ";
		for (int i = 0; i < Graph[temp].size(); i++) {
			int to = Graph[temp][i];

			int b = v[temp] + 1;
			int c = min(h[temp], dis[to]);
			if ((!visited[to]) || (v[to] == -1) || (visited[to] && b <= v[to] && c > h[to])) {
				v[to] = b;
				h[to] = c;
				if (to != f) q.push(to);
				visited[to] = true;
			}
		}
	}
	//cout << endl;
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

	int n, e; cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		dis[i] = -1;
		visited[i] = false;
	}
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		Graph[x].pb(y);
		Graph[y].pb(x);
	}
	cin >> s >> f >> r;
	bfs(r);
	// for(int i=1;i<=n;i++){
	// 	cout<<dis[i]<<" ";
	// }
	//cout<<endl;
	for (int i = 1; i <= n; i++) {
		h[i] = 0;
		v[i] = -1;
		visited[i] = false;
	}
	bfs_2(s);
	// for(int i=1;i<=n;i++){
	// 	cout<<h[i]<<" ";
	// }
	cout << h[f] << endl;



	return 0;
}