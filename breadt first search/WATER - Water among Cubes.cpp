#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 1e2 + 5;
int Graph[N][N];
int visited[N][N];
int n, m;
int vol;

struct node {
    int x_cord, y_cord, cost;

    node() {
        x_cord = y_cord = cost = 1e4 + 5;
    }
    node(int r, int c, int p) {
        x_cord = r, y_cord = c, cost = p;
    }
};

typedef bool (*comp) (node, node);

bool compare(node a, node b) {
    return a.cost > b.cost;
}

int row[5] = {0, 1, -1, 0, 0};
int col[5] = {0, 0, 0, 1, -1};

void bfs() {
    priority_queue <node, vector<node>, comp> q(compare);
    for (int i = 1; i <= m; i++) {
        q.push(node(1, i, Graph[1][i]));
    }
    for (int i = 1; i <= m; i++) {
        q.push(node(n , i, Graph[n][i]));
    }
    for (int i = 1; i < n ; i++) {
        q.push(node(i, 1, Graph[i][1]));
    }
    for (int i = 1; i < n ; i++) {
        q.push(node(i, m , Graph[i][m]));
    }
    while (!q.empty()) {
        node cur = q.top();
        while (!q.empty()) {
            node temp = q.top();
            if (temp.cost > cur.cost)
                break;
            q.pop();
            if (visited[temp.x_cord][temp.y_cord])
                continue;
            visited[temp.x_cord][temp.y_cord] = 1;
            vol += cur.cost - temp.cost;
            for (int i = 1; i <= 4; i++) {
                int xx = temp.x_cord + row[i];
                int yy = temp.y_cord + col[i];
                if (xx >= 1 && yy >= 1 && xx <= n && yy <= m)
                    q.push(node(xx, yy, Graph[xx][yy]));
            }
        }
    }
}

void solve() {
    vol = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> Graph[i][j];
        }
    }
    bfs();
    cout << vol << endl;
}

int32_t main() {

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // code starts

    int t; cin >> t; while (t--) {
        solve();
    }

    return 0;
}