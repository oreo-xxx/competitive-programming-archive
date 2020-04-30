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
	ll  n,x, m,k;cin >>n>> x>> m>> k;
	ll M=max(n, max(x,m));
	ll ans=n+x+m+pow(2,k)* M-M;
    cout << ans << endl;
}
