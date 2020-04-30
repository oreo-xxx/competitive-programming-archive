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
	vector<ll> a(n);
	for(int i = 0; i < n; ++i)cin >>a[i];
	ll sum =0;
	ll ans=0;
	for(int i = 0; i < n; ++i){
		sum +=a[i];
		if(sum>x){
			a[i] -=(sum-x);
			ans+=(sum-x);
                }
                sum=a[i];
      }
      cout << ans << endl;
}
