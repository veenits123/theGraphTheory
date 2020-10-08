#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod (int)1e9+7
#define endl '\n'
#define mp make_pair

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;
int n, m;

int row[] = {0, 1, -1, 0};
int col[] = {1, 0, 0, -1};

bool valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void solve() {

	cin >> n >> m;
	int q; cin >> q;
	while (q--) {
		int rx, ry;
		int c1x, c1y;
		int c2x, c2y;
		cin >> rx >> ry;
		cin >> c1x >> c1y;
		cin >> c2x >> c2y;
		bool flag = false;

		int xd = min(c1x + abs(ry - c1y), c2x + abs(ry - c2y));
		int yd = min(c1y + abs(rx - c1x), c2y + abs(rx - c2x));
		int xm = max(c1x - abs(ry - c1y), c2x - abs(ry - c2y));
		int ym = max(c1y - abs(rx - c1x), c2y - abs(rx - c2x));

		if (xd > rx || yd > ry || rx > xm || ry > ym)
			flag = true;

		if (!flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
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