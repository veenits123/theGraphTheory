#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long int
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e3 + 5;
int Graph[N][N];
int visited[N][N];
P parent[N][N];
int n, m;
int start;

int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

void bfs(P src) {
	queue <P> q;
	parent[src.F][src.S] = { -1, -1};
	q.push(src);
	visited[src.F][src.S] = 1;
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		//cout<<Graph[temp.F][temp.S]<<" ";
		for (int i = 0; i < 4; i++) {
			int x = temp.F + row[i];
			int y = temp.S + col[i];
			if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y])
				continue;
			q.push({x, y});
			parent[x][y] = temp;
			visited[x][y] = 1;
		}
	}
	//cout<<endl;

}

int shortest_path(P des) {
	int c = 0;
	if (!visited[des.F][des.S]) {
		//cout << "No Path!!" << endl;
		return 0;
	}
	else {
		vector <P> path;
		for (P i = des; i != make_pair((int) - 1, (int) - 1); i = parent[i.F][i.S]) {
			path.pb({i.F, i.S});
		}
		reverse(path.begin(), path.end());
		//cout << "Path : ";
		for (auto x : path) {
			//cout << x.F << " "<<x.S<<endl;
			if (Graph[x.F][x.S] != start)
				c++;
		}
		//cout << endl;
	}
	return c;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				Graph[x][y] = 0;
				visited[x][y] = 0;
			}
		}
		cin >> n >> m;

		char ch;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				cin >> ch;
				Graph[x][y] = ch - '0';
			}
		}
		start = Graph[0][0];

		bfs({0, 0});

		cout << shortest_path({n - 1, m - 1}) << endl;
	}
	return 0;
}