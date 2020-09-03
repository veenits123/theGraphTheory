#include <iostream>
#include <map>
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

const int N = 4e1;
double dis[N][N];
int n, m;
map <string, int> node;

void floyd_warshall() {
	for (int k = 1; k < N; k++) {
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				dis[i][j] = max(dis[i][j], dis[i][k] * dis[k][j]);
			}
		}
	}
}

void solve() {
	int tc = 1;
	while (true) {
		cin >> n;
		if (n == 0)
			return ;

		node.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dis[i][j] = 0.0;
			}
		}

		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			node[s] = i;
		}
		cin >> m;

		for (int i = 1; i <= m; i++) {
			string c1, c2;
			double cost;
			cin >> c1 >> cost >> c2;
			dis[node[c1]][node[c2]] = cost;
		}
		floyd_warshall();

		bool ans = false;

		for (int i = 1; i <= n; i++) {
			if (dis[i][i] > 1.0) {
				ans = true;
				break;
			}
		}
		if (ans)
			cout << "Case " << tc++ << ": Yes" << endl;
		else
			cout << "Case " << tc++ << ": No" << endl;
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