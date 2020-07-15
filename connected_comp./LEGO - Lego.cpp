#include <iostream>
#include <map>
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

map <int, pair<P, P>> ord;

void solve() {
	int n; cin >> n;
	vector <int> Graph[n];
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		ord[i] = {{x1, y1}, {x2, y2}};
	}
	// for (auto x : ord)
	// 	cout << x.S.F.F << " " << x.S.S.F << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if ((ord[i].F.S == ord[j].S.S && abs(ord[i].F.F - ord[j].S.F) >= 1) ||
			        (ord[i].S.S == ord[j].F.S && abs(ord[i].S.F - ord[j].F.F) >= 1)) {
				Graph[i].pb(j);
				Graph[j].pb(i);
				cout << i << " " << j << endl;
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (auto x : Graph[i]) {
	// 		cout << x << " ";
	// 	}
	// 	cout << endl;
	// }

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