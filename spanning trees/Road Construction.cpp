#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

const int N = 1e5 + 5;
int parent[N];
int sz[N];
int n, m;

void init() {
	REP(i, 1, N) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int n) {
	if (n == parent[n])
		return n;
	return parent[n] = find(parent[n]);
}

void unite(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x != y) {
		if (sz[x] < sz[y])
			swap(x, y);
		parent[y] = x;
		sz[x] += sz[y];
		sz[y] = 0;
	}
}

void solve() {

	cin >> n >> m;

	int ans = 0;
	int comp = n;

	while (m--) {
		int u, v; cin >> u >> v;
		int x = find(u), y = find(v);
		if (x != y) {
			comp--;
			unite(x, y);
		}
		ans = max(ans, max(sz[x], sz[y]));
		cout << comp << " " << ans << endl;
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

	init();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}