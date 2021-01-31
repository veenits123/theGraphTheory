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

map <P, int> way;
map <P, int> dis;
int n;

void bfs(int sx, int sy) {
	dis[ {sx, sy}] = 0;
	queue <P> q;
	q.push({sx, sy});
	while (!q.empty()) {
		int r = q.front().F;
		int c = q.front().S;
		int d = dis[ {r, c}];
		q.pop();
		REP(i, -1, 1) {
			REP(j, -1, 1) {
				int x = r + i;
				int y = c + j;
				if (dis[ {x, y}] || !way[ {x, y}])
					continue;
				dis[ {x, y}] = d + 1;
				q.push({x, y});
			}
		}
	}
}

void solve() {

	int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
	cin >> n;

	REP(i, 1, n) {
		int r, a, b; cin >> r >> a >> b;
		REP(x, a, b)
		way[ {r, x}] = 1;
	}
	bfs(x0, y0);

	if (!dis[ {x1, y1}])
		cout << -1 << endl;
	else
		cout << dis[ {x1, y1}] << endl;

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