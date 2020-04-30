#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main() {
	ll  n,x;cin >>n>> x;
	ll ans=n-1;
	if(x>=n){++ans;}
    cout << ans << endl;
}
