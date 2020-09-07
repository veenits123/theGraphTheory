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
#define FOR(a,b) for(int i=a;i<b;i++)
#define REP(a,b) for(int i=a;i<=b;i++)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod 1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;
vb is_prime(N);
vi prime;

void sieve() {
	for (int i = 2; i * i < N; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j < N; j += i) {
				is_prime[j] = true;
			}
		}
	}
	for (int i = 1001; i < 10001; i += 2)
		if (!is_prime[i])
			prime.pb(i);
}

bool is_connected(int a, int b) {
	int cnt = 0;
	while (a && b) {
		if (a % 10 != b % 10)
			cnt++;
		a /= 10;
		b /= 10;
	}
	return cnt == 1;
}

vi Graph[N];
vi vis;
vi dis(N);

void build_graph() {
	for (int i = 0; i < prime.size(); i++) {
		for (int j = i + 1; j < prime.size(); j++) {
			if (is_connected(prime[i], prime[j])) {
				//method - I; compressing index;
				// Graph[i].pb(j);
				// Graph[j].pb(i);

				//method - II; as it is;
				Graph[prime[i]].pb(prime[j]);
				Graph[prime[j]].pb(prime[i]);
			}
		}
	}
}

P srcNdes(int a, int b) {
	int st = -1, en = -1;
	for (int i = 0; i < prime.size(); i++) {
		if (a == prime[i])
			st = i;
		if (b == prime[i])
			en = i;
	}
	return {st, en};
}

int bfs(int src, int des) {
	vis[src] = 1;
	queue <int> q;
	q.push(src);
	dis[src] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == des) {
			return dis[cur];
		}
		for (int to : Graph[cur]) {
			if (!vis[to]) {
				q.push(to);
				vis[to] = 1;
				dis[to] = dis[cur] + 1;
			}
		}
	}
	return -1;
}

void solve() {

	vis.assign(N, 0);

	int s, e; cin >> s >> e;

	//method - I; compressing index;
	//P ind = srcNdes(s, e);
	//int ans = bfs(ind.F, ind.S);

	//method - II; as it is;
	int ans = bfs(s, e);
	if (ans == -1)
		cout << "Impossible" << endl;
	else
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

	sieve();
	build_graph();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}