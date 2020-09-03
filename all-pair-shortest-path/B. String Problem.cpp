#include <iostream>
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

int dis[30][30];
string s, t;
int n;
const int inf = 1e9;

void floyd_warshall() {
	for (int k = 0; k < 30; k++) {
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}

void solve() {
	cin >> s;
	cin >> t;
	cin >> n;
	if (s.size() != t.size()) {
		cout << -1 << endl;
		return ;
	}
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (i == j)
				dis[i][j] = 0;
			else
				dis[i][j] = inf;
		}
	}
	for (int i = 1; i <= n; i++) {
		char u, v;
		int w;
		cin >> u >> v >> w;
		if (w > dis[(u - 'a')][(v - 'a')])
			continue;
		dis[(u - 'a')][(v - 'a')] = w;
		//dis[(v - 'a')][(u - 'a')] = w;
	}
	floyd_warshall();
	// for (int i = 0; i < 30; i++) {
	// 	for (int j = 0; j < 30; j++) {
	// 		cout << dis[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans = 0;
	string res = "";

	for (int i = 0; i < s.size(); i++) {
		int relax = 1e9;
		char x;
		for (int j = 0; j < 30; j++) {
			if (relax > dis[s[i] - 'a'][j] + dis[t[i] - 'a'][j]) {
				relax = dis[s[i] - 'a'][j] + dis[t[i] - 'a'][j];
				x = j + 'a';
			}
		}
		res += x;
		ans += relax;
	}
	if (ans >= inf) {
		cout << -1 << endl;
		return ;
	}
	cout << ans << endl;
	cout << res << endl;

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