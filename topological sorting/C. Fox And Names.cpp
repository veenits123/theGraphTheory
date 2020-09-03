#include <iostream>
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

const int N = 1e2 + 5;
vector <int> Graph[N];
vector <int> vis, act;
int n;
vector <string> s;
string ans;

typedef vector<int> vi;
typedef vector<string> vs;

void dfs(int src) {
	vis[src] = 1;
	act[src] = 1;
	for (auto to : Graph[src]) {
		if (act[to]) {
			cout << "Impossible";
			exit(0);
		}
		if (!vis[to])
			dfs(to);
	}
	ans += src + 'a';
	act[src] = 0;
}

void solve() {
	vis = vi(N, 0);
	act = vi(N, 0);
	s = vs(N, "");
	ans = "";

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (i > 0) {
			int ptr = 0;
			while (ptr < s[i].size() && ptr < s[i - 1].size() && s[i][ptr] == s[i - 1][ptr])
				ptr++;
			if (s[i].size() == ptr) {
				cout << "Impossible" << endl;
				return ;
			}
			if (ptr < s[i - 1].size())
				Graph[s[i][ptr] - 'a'].pb(s[i - 1][ptr] - 'a');
		}
	}
	for (int i = 0; i < 26; i++) {
		if (!vis[i])
			dfs(i);
	}
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}