#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
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

const int N = 1e5 + 5;
vector <P> Graph[N];
vector <int> dis;
int n;
map <string, int> city;

typedef vector <int> vi;

void dijsktra(int src, int des) {
	priority_queue <P, vector<P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	while (!q.empty()) {
		P temp = q.top();
		q.pop();
		int prev = temp.S;
		int prev_c = temp.F;

		if (prev == des)
			break;

		for (auto to : Graph[prev]) {
			int cost = to.S;
			int cur = to.F;
			if (dis[cur] > prev_c + cost) {
				dis[cur] = prev_c + cost;
				q.push({dis[cur], cur});
			}
		}
	}
}

void solve() {
	cin >> n;
	city.clear();//important;
	for (int i = 1; i <= n; i++) {
		Graph[i].clear();//important ;)
		string s; cin >> s;
		city[s] = i;
		int con; cin >> con;
		while (con--) {
			int u, w; cin >> u >> w;
			Graph[i].pb({u, w});
			//Graph[u].pb({i, w});
		}
	}
	int r; cin >> r;
	while (r--) {
		string s1, s2; cin >> s1 >> s2;
		dis = vi(N, 1e18);//important ;)
		dijsktra(city[s1], city[s2]);
		cout << dis[city[s2]] << endl;
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