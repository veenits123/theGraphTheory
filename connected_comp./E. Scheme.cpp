#include <iostream>
#include <vector>
#include <map>
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
int vis[N];
vector <int> start, en;
map <int, int> indeg;
int n;
int a[N];

int dfs(int src) {
	vis[src] = 1;
	if (vis[a[src]])
		return src;
	return dfs(a[src]);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		indeg[a[i]]++;
	}
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (!indeg[i]) {
			start.pb(i);//beginning
			en.pb(dfs(i));//ending
			k++;
		}
	}
	int ans = k;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			k++;
			start.pb(i);
			en.pb(dfs(i));
		}
	}

	if (ans == 0 && k == 1) {
		cout << 0 << endl;
		return ;
	}
	cout << k << endl;
	for (int i = 0; i < k; i++) {
		//cout << i << " " << (i + 1) % k << endl;
		cout << en[i] << " " << start[(i + 1) % k] << endl;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}