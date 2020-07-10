#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mp map<int,int>
#define vi vector<int>
#define pq priority_queue<int>
#define pqm priority_queue<int,vi,greater<int> >
#define mod 1e9+7
#define inf 1e18
#define sp(x,y) fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr=new type[n];
#define tc(x) int x;cin>>x;while(x--)
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define gcd(x,y) __gcd(x,y)
#define s2i(x) stoi(x)
#define i2s(x) to_string(x)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define endl '\n'
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

void solve() {
	float x = 5;
	x = x / 7;
	cout << sp(x, 5);
}

int32_t main() {

	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//tc(t)
	solve();

	return 0;
}