#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long
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

const int N = 1e5 + 5;
vector <P> Graph[N];
vi dis;
int des;
int n;

const int inf = 1e18;

typedef vector <int> vii;

void dijkstra(int src) {

  priority_queue <P, vector<P>, greater<P>> q;
  q.push({0, src});
  dis[src] = 0;

  while (!q.empty()) {
    int cost = q.top().F;
    int cur = q.top().S;
    q.pop();
    if (cost > dis[cur])
      break;
    for (auto to : Graph[cur]) {
      int w = to.S;
      int node = to.F;
      if (dis[node] > cost + w) {
        dis[node] = cost + w;
        q.push({dis[node], node});
      }
    }
  }
  int max_dis = 0;;
  REP(i, 1, n) {
    if (dis[i] > max_dis) {
      max_dis = dis[i];
      des = i;
    }
  }
}

void solve() {

  dis = vii(N, inf);
  cin >> n;
  REP(i, 0, n)
  Graph[i].clear();

  REP(i, 1, n - 1) {
    int u, v, w; cin >> u >> v >> w;
    Graph[u].pb({v, w});
    Graph[v].pb({u, w});
  }
  dijkstra(1);

  dis = vii(N, inf);
  dijkstra(des);

  cout << dis[des] << endl;

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

  int t; cin >> t; while (t--)
    solve();

  return 0;
}