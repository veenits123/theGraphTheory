#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define node pair<int,P>
const int inf = 1e18;

vector <int> bfs(int src, vector <vector <pair <int, int>>> &Graph) {
  int n = Graph.size();
  vector <int> dis(n, inf);
  dis[src] = 0;

  queue <int> q;
  q.push(src);
  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    for (auto &x : Graph[temp]) {
      int to = x.F;
      int w = x.S;
      if (dis[to] > dis[temp] + w) {
        dis[to] = dis[temp] + w;
        q.push(to);
      }
    }
  }
  return dis;
}

mt19937 gen;

vector <int> par;

int find(int a) {
  if (par[a] == a)
    return a;
  return par[a] = find(par[a]);
}

void unite(int a, int b) {
  if (gen() % 2)
    swap(a, b);
  par[a] = b;
}

void solve() {

  int n; cin >> n;

  par.resize(n + 1);
  iota(par.begin(), par.end(), 0);
  vector <vector <int>> mat(n + 1, vector <int>(n + 1));
  vector <node> edges;
  vector <vector <pair <int, int>>> Graph(n + 1);

  REP(i, 1, n) {
    REP(j, 1, n) {
      cin >> mat[i][j];
      edges.pb({mat[i][j], {i, j}});
    }
  }
  sort(all(edges));

  for (auto &x : edges) {
    int u = x.S.F;
    int v = x.S.S;
    int w = x.F;
    int nu = find(u), nv = find(v);
    if (nu == nv)
      continue;
    Graph[u].pb({v, w});
    Graph[v].pb({u, w});
    unite(nu, nv);
  }

  REP(i, 1, n) {
    vector <int> dis = bfs(i, Graph);
    REP(j, 1, n) {
      if ((dis[j] != mat[i][j]) || (mat[i][j] == 0 && i != j)) {
        cout << "NO" << endl;
        return ;
      }
    }
  }
  cout << "YES" << endl;

  return ;
}

int32_t main() {

  /* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
  → → → → → → → → → → → → → → → → → → → → → → → → → → → → */

  ios_base:: sync_with_stdio(false);
  cin.tie(NULL); //cout.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  /* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
  → → → → → → → → → → → → → → → → → → → → → → → → → → → → */

  gen.seed(time(0));

  //int t;cin>>t;while(t--)
  solve();

  return 0;
}