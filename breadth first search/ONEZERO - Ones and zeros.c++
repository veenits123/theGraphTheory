#include <iostream>
#include <queue>

using namespace std;

#define int long long
#define F first
#define S second
#define P pair<string,int>
#define endl '\n'

int n;
string ans;

void bfs() {
	queue <P> q;
	q.push({"1", 1});
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		//cout<<temp.F<<" "<<temp.S<<endl;

		int a = temp.S;
		if (a % n == 0) {
			ans = temp.F;
			return ;
		}
		temp.S %= n;

		q.push({temp.F + "0", temp.S * 10 + 0});
		q.push({temp.F + "1", temp.S * 10 + 1});
	}
}

void solve() {
	cin >> n;
	bfs();
	cout << ans << endl;
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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}