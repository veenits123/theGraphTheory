#include <iostream>
#include <vector>

using namespace std;

#define int long long int
#define pb push_back
#define endl '\n'

const int N = 4e1 + 5;
vector <string> Graph;
int vis[N][N];
int n, m, spike;
int ans = 0;

int row[4] = { -1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool is_safe(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
		return false;
	else
		return true;
}

bool can_go(int i, int j, int &sp) {
	if (Graph[i][j] == '#')
		return false;
	if (Graph[i][j] == '.' || Graph[i][j] == 'x')
		return true;
	if (sp > 0 && Graph[i][j] == 's') {
		sp--;
		return true;
	}
	return false;
}

void dfs(int i, int j, int &spk) {
	vis[i][j] = 1;
	if (Graph[i][j] == 'x' && (2 * (spike - spk) <= spike)) {
		ans = 1;
		return ;
	}
	else {
		for (int it = 0; it < 4; it++) {
			int temp = spk;
			int x = i + row[it];
			int y = j + col[it];
			if (is_safe(x, y) && can_go(x, y, temp))
				dfs(x, y, temp);
		}
	}
	vis[i][j] = 0;
	return ;
}

void solve() {
	cin >> n >> m >> spike;
	int s = spike;
	string ch;
	for (int i = 0; i < n; i++) {
		cin >> ch;
		Graph.pb(ch);
	}
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Graph[i][j] == '@') {
				x = i; y = j;
				break;
			}
		}
	}
	dfs(x, y, spike);

	if (ans)
		cout << "SUCCESS" << endl;
	else
		cout << "IMPOSSIBLE" << endl;
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