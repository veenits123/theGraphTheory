#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define int long long int
#define F first
#define S second
#define P pair<string,int>
#define pb push_back
#define endl '\n'

const int N = 1e4 + 5;
vector <int> valid;
int vis[N];
int n, m;

string bfs() {
	queue <P> q;
	for (int i = 0; i < valid.size(); i++) {
		if (valid[i] == 0) continue;
		string ans = "";

		char ch = valid[i] + '0';
		ans += ch;

		int mod = valid[i] % n;
		if (mod == 0)
			return ans;

		q.push({ans, mod});
		//vis[mod]++;
	}
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		//cout<<temp.F<<" "<<temp.S<<endl;

		string num = temp.F;
		int mod = temp.S;

		for (int i = 0; i < valid.size(); i++) {
			char ch = valid[i] + '0';

			int nw_mod = (mod * 10 + valid[i]) % n;

			if (vis[nw_mod] > 1)
				continue ;

			if (nw_mod == 0)
				return num + ch;

			q.push({num + ch, nw_mod});
			vis[nw_mod]++;
		}
	}
	return "-1";
}

void solve() {
	int tc = 1;
	while (cin >> n >> m) {
		int ignore[11] = {0};
		while (m--) {
			int x; cin >> x;
			ignore[x] = 1;
		}
		valid.clear();
		for (int i = 0; i < 10; i++) {
			if (ignore[i] == 0)
				valid.pb(i);
		}
		memset(vis, 0, sizeof(vis));

		cout << "Case " << tc++ << ": " << bfs() << endl;
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

	solve();

	return 0;
}