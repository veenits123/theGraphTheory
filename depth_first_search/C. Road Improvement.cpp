#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 2e5 + 5;
vector <P> Graph[N];
vector <int> ans[N];
int day;
int n;

void dfs(int src, int par, int no) {
	int temp = 0;
	//cout<<src<<" "<<par<<endl;
	for (auto to : Graph[src]) {
		int child = to.F;
		int road = to.S;
		if (child != par) {
			temp++;
			if (temp == no)
				temp++;
			ans[temp].pb(road);

			day = max(day, temp);
			dfs(child, src, temp);
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		Graph[u].pb({v, i});
		Graph[v].pb({u, i});
	}

	dfs(1, 0, 0);

	//cout << day << endl;

	for (int i = 1; i <= day; i++) {
		//cout << ans[i].size() << " ";

		for (auto x : ans[i])
			//cout << x << " ";

			cout << endl;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}