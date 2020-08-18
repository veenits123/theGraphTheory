#include <iostream>
#include <deque>
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

class Solution {
public:
	bool is_valid(int i, int j, int m, int n) {
		return (i >= 0 && i < m && j >= 0 && j < n);
	}

	pair<int, int> same(int i, int j, int val) {
		if (val == 1)
			return make_pair(i, j + 1);
		if (val == 2)
			return make_pair(i, j - 1);
		if (val == 3)
			return make_pair(i + 1, j);
		return make_pair(i - 1, j);
	}

	int minCost(vector<vector<int>>& Graph) {
		int m = Graph.size();
		int n = Graph[0].size();
		vector<vector<int>> dis(m, vector<int>(n, 1e9));
		deque <pair<int, int>> q;
		q.push_front({0, 0});
		dis[0][0] = 0;
		while (!q.empty()) {
			int tx = q.front().first;
			int ty = q.front().second;
			q.pop_front();
			for (int i = 1; i <= 4; i++) {
				pair<int, int> temp = same(tx, ty, i);
				int r = temp.first;
				int c = temp.second;
				//cout << r << " " << c << endl;
				int w = (Graph[tx][ty] != i ? 1 : 0);
				if (is_valid(r, c, m, n)) {
					if (dis[r][c] > w + dis[tx][ty]) {
						dis[r][c] = w + dis[tx][ty];
						//cout << (Graph[r][c] == i) << endl;
						if (w == 0)
							q.push_front({r, c});
						else
							q.push_back({r, c});
					}
				}
			}
		}
		return dis[m - 1][n - 1];
	}
};

void solve() {
	int m, n; cin >> m >> n;
	vector<vector<int>> gr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> gr[i][j];
		}
	}
	int ans = Solution().minCost(gr);
	cout << ans << endl;

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