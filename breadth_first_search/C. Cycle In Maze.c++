#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e3 + 5;
char Graph[N][N];
int vis[N][N];
int dis[N][N];
vector <char> ans;
int n, m, k;
int x, y;

int row[5] = {0, 1, 0, 0, -1};
int col[5] = {0, 0, -1, 1, 0};

bool is_valid(int i, int j) {
	return (i >= 1 && j >= 1 && i <= n && j <= m);
}

char path[5] = {'X', 'D', 'L', 'R', 'U'};

void bfs(int x, int y) {
	queue <P> q;
	q.push({x, y});
	vis[x][y] = 1;
	dis[x][y] = 0;
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		//cout<<temp.F<<" "<<temp.S<<endl;
		for (int i = 1; i <= 4; i++) {
			int r = temp.F + row[i];
			int c = temp.S + col[i];
			if (!vis[r][c] && is_valid(r, c) && Graph[r][c] != '*') {
				q.push({r, c});
				vis[r][c] = 1;
				dis[r][c] = dis[temp.F][temp.S] + 1;
			}
		}
	}
}

void solve() {
	cin >> n >> m >> k;

	if (k & 1) {
		cout << "IMPOSSIBLE";
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
			if (Graph[i][j] == 'X') {
				x = i;
				y = j;
			}
		}
	}

	bfs(x, y);
	while (k) {
		bool flag = false;
		for (int i = 1; i <= 4; i++) {
			if (x + row[i] >= 1 && x + row[i] <= n && y + col[i] >= 1
			        && y + col[i] <= m && Graph[x + row[i]][y + col[i]] != '*') {
				//cout<<"ffjf";
				if (k == dis[x][y] && k - 1 != dis[x + row[i]][y + col[i]])
					continue;
				k--;
				flag = true;
				ans.pb(path[i]);
				x += row[i];
				y += col[i];
				break;
			}
		}
		if (!flag) {
			cout << "IMPOSSIBLE";
			return ;
		}
	}
	for (auto it : ans)
		cout << it;
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