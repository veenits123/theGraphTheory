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
vector <int> dis(N), parent(N);

void bfs(int src) {
	queue <int> q;
	q.push(src);
	visited[src] = true;
	parent[src] = -1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 0; i < Graph[temp].size(); i++) {
			int to = Graph[temp][i];
			if (!visited[to]) {
				q.push(to);
				visited[to] = true;
				dis[to] = dis[temp] + 1;
				parent[to] = temp;
			}
		}
	}
	cout << endl;
}

void shortest_path(int des) {
	if (!visited[des]) {
		cout << "No Path!!" << endl;
	}
	else {
		vector <int> path;
		for (int i = des; i != -1; i = parent[i]) {
			path.pb(i);
		}
		reverse(path.begin(), path.end());
		cout << "Path : ";
		for (auto x : path) {
			cout << x << " ";
		}
		cout << endl;
	}
}

int connected_comp(int nodes) {
	int count = 0;
	for (int i = 1; i <= nodes; i++) {
		if (visited[i]) continue;
		bfs(i);
		count++;
	}
	return count;
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
	for (int i = 0; i < e; i++) {
		int x, y; cin >> x >> y;
		Graph[x].pb(y);
		Graph[y].pb(x);
	}
	bfs(1);
	shortest_path(5);
	//cout << connected_comp(n) << endl;


	return 0;
}