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

//#define int long long int
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

const int N = 2005;
char Graph[N][30];
int n, m;

#define node pair <int,P>
vector <node> edges;

void genEdges() {
	REP(i, 1, n) {
		REP(j, i + 1, n) {
			int temp = 0;
			REP(k, 1, m) {
				int w = abs((Graph[i][k] - 'a') - (Graph[j][k] - 'a'));
				temp = max(temp, w);
			}
			edges.pb({temp, {i, j}});
		}
	}
}

int par[N];

void init() {
	REP(i, 1, N)
	par[i] = i;
}

int find(int a) {
	if (a == par[a])
		return a;
	return par[a] = find(par[a]);
}

void unite(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x != y) {
		if (x < y)
			swap(x, y);
		par[y] = x;
	}
}

void solve() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", Graph[i] + 1);
	// cin >> n >> m;
	// REP(i, 1, n) {
	// 	REP(j, 1, m) {
	// 		cin >> Graph[i][j];//in don't know fucking why cin/cout giving WA :\
	// 	}
	// }

	genEdges();

	sort(all(edges));

	int cnt = 0;
	int ans = 0;
	for (auto x : edges) {
		int u = x.S.F;
		int v = x.S.S;
		int w = x.F;
		if (find(u) != find(v)) {
			ans = w;
			unite(v, u);
			cnt++;
			if (cnt == n - 1)
				break;
		}
	}
	printf("%d\n", ans);
	//cout << ans << endl;

	return ;
}

int main() {

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