#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define int long long int
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 10;
int Graph[N][N];
bool visited[N][N];
int row[N] = {0, 1, 2, 2, -1, -2, -1, -2, 1, 1};
int col[N] = {0, 2, 1, -1, 2, -1, -2, 1, -2, 2};

int bfs(int x1, int y1, int x2, int y2) {

  queue <P> q;

  P src;
  src.F = x1;
  src.S = y1;

  q.push(src);

  memset(Graph, 0, sizeof(Graph));
  memset(visited, 0, sizeof(visited));

  while (!q.empty()) {
    P temp = q.front();
    q.pop();

    if (temp.F == x2 && temp.S == y2) {
      return Graph[x2][y2];
    }
    for (int i = 1; i <= 8; i++) {

      int r = temp.F + row[i];
      int c = temp.S + col[i];

      if (r < 1 || c < 1 || r > 8 || c > 8) {
        continue;
      }

      else {
        visited[r][c] = 1;
        Graph[r][c] = Graph[temp.F][temp.S] + 1;
        q.push({r, c});
      }
    }
  }
  return -1;
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
    string src, des; cin >> src >> des;
    cout << bfs(src[0] - 'a' + 1, src[1] - '0', des[0] - 'a' + 1, des[1] - '0') << endl;
  }



  return 0;
}