#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int a, b;
vector <int> v;

void solve() {
	cin >> a >> b;
	bool flag = false;
	while (b) {

		if (b % 2 == 0) {
			v.pb(b);
			b /= 2;
		}
		else if (b % 10 == 1) {
			v.pb(b);
			b /= 10;
		}
		else {
			cout << "NO";
			return ;
		}
		if (a == b) {
			flag = true;
			break;
		}
	}
	if (flag) {
		v.pb(a);
		reverse(v.begin(), v.end());
		cout << "YES" << endl;
		cout << v.size() << endl;
		for (auto x : v)
			cout << x << " ";
	}
	else
		cout << "NO";
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