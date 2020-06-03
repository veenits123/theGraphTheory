#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

#define int long long int
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 3e3 + 5;
vector <int> Graph[N];
int vis[N][N];
P par[N][N];
int n, m, k;
map <pair<P, int>, int> save;

P bfs() {
	queue <P> q;
	q.push({1, 1});
	vis[1][1] = 1;
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		if (temp.S == n)
			return temp;
		//cout<<temp<<" ";
		for (auto x : Graph[temp.S]) {
			if (vis[temp.S][x] || save[ {temp, x}]) continue;
			vis[temp.S][x] = 1;
			q.push({temp.S, x});
			par[temp.S][x] = temp;
		}
	}
	return { -1, -1};
}

void solve() {
	cin >> n >> m >> k;
	while (m--) {
		int x, y; cin >> x >> y;
		Graph[x].pb(y);
		Graph[y].pb(x);
	}

	while (k--) {
		int a, b, c; cin >> a >> b >> c;
		save[ {{a, b}, c}] = 1;
	}

	P ans = bfs();
	//cout<<ans.F<<" "<<ans.S;

	if (ans == make_pair((int) - 1, (int) - 1)) {
		cout << -1;
		return ;
	}
	else {
		vector <int> p;
		for (P i = ans; i != make_pair((int)1, (int)1); i = par[i.F][i.S]) {
			p.pb(i.S);
		}
		p.pb(1);
		reverse(p.begin(), p.end());
		cout << p.size() - 1 << endl;
		for (auto x : p)
			cout << x << " ";
	}
	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--){}
	solve();


	return 0;
}