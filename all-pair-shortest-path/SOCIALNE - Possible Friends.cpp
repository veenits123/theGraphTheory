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

const int N = 1e2 + 5;
string Graph[N];
string s;
int n;
int possible[N];

void floyd_warshall() {
	for (int k = 0; k < n; k++) {
		for (int i = k + 1; i < n; i++) {
			if (Graph[k][i] == 'N') {
				for (int j = 0; j < n; j++) {
					if (Graph[i][j] == 'Y' && Graph[k][j] == 'Y') {
						//j is a common friend of i and k;
						possible[k]++;
						possible[i]++;
						break;
					}
				}
			}
		}
	}
}

void solve() {
	while (cin >> s) {
		Graph[0] = s;
		n = s.size();
		for (int i = 1; i < n; i++) {
			cin >> Graph[i];
		}
		for (int i = 0; i < n; i++)
			possible[i] = 0;

		floyd_warshall();

		int ans = 0, ind = 0;
		for (int i = 0; i < n; i++) {
			if (possible[i] > ans) {
				ind = i;
				ans = possible[i];
			}
		}
		cout << ind << " " << ans << endl;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}