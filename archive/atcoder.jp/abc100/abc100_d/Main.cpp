#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
ll calc(int type, ll x, ll y, ll z){
	if(type == 0){return x + y + z;}
	if(type == 1){return x + y - z;}
	if(type == 2){return x - y + z;}
	if(type == 3){return x - y - z;}
	if(type == 4){return -x + y + z;}
	if(type == 5){return -x + y - z;}
	if(type == 6){return -x - y + z;}
	if(type == 7){return -x - y - z;}
}
int main(){
    int n, m; cin >>n >> m;
    vector<ll> x(n), y(n), z(n);
    for(int i = 0; i < n; ++i){
    	  cin >> x[i] >> y[i] >> z[i];
    }
    ll ans = -1*INF32;
  for(int t = 0; t<8; ++t){
    vector<ll> vec(n);
    for(int i = 0; i < n; ++i){
    	vec[i] = calc(t, x[i], y[i], z[i]);
    }
    sort(vec.begin(), vec.end(), greater<ll>());
    ll tmp = 0;
    for(int i = 0; i < m; ++i){tmp += vec[i];}
    ans=max(ans, tmp);
  }
    cout << ans << endl;
    return 0;
}