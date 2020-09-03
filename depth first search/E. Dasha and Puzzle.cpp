#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 3e1 + 5;
vector <int> Graph[N];
int vis[N];
int n;

vector <P> ans(N);

int row[] = {1, 0, -1, 0};
int col[] = {0, 1, 0, -1};

void dfs(int src, int dir, int len) {
    vis[src] = 1;
    dir = (dir + 3) % 4;
    for (auto to : Graph[src]) {
        if (!vis[to]) {
            ans[to].F = ans[src].F + row[dir] * len;
            ans[to].S = ans[src].S + col[dir] * len;
            dfs(to, dir, len >> 1LL);
            dir = (dir + 1) % 4;
        }
    }
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        Graph[u].pb(v);
        Graph[v].pb(u);
    }

    for (int i = 1; i <= n; i++) {
        if (Graph[i].size() > 4) {
            cout << "NO";
            return ;
        }
    }

    dfs(1, 0, 1LL << n);
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i].F << " " << ans[i].S << endl;
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

    //int t;cin>>t;while(t--)
    solve();

    return 0;
}