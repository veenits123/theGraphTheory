#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 1e2 + 5;
int vis[N];
vector <int> Graph[27];
int n;
string ans = "";

void dfs(int src) {
	vis[src] = 3;
	for (auto to : Graph[src]) {
		if (vis[to] != 3) {
			vis[to] = 3;
			dfs(to);
		}
	}
	ans += (char)(src + 'a');
}

void solve() {
	cin >> n;
	for (int inp = 0; inp < n; inp++) {
		string s; cin >> s;
		for (int i = 0; i < s.size() - 1; i++) {
			Graph[s[i] - 'a'].pb(s[i + 1] - 'a');
			vis[s[i + 1] - 'a'] = 1;
		}
		if (vis[s[0] - 'a'] != 1) {
			vis[s[0] - 'a'] = 2;
		}
	}
	for (int i = 0; i < 27; i++) {
		if (vis[i] == 2) {
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;

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