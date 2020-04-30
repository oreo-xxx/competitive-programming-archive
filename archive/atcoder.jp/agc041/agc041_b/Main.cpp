#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	ll n,m,v,p;
	cin >> n >> m >> v >> p;
	map<ll, ll> mp;
	for(int i = 0; i < n; ++i){
		int a;cin >> a;++mp[a];
    }
    vector<pll> vec;
    for(auto it : mp){
      vec.push_back({it.first, it.second});
    }
    ll N= vec.size();
    vector<ll> sum(N+1);
    for(int i = 0; i < N; ++i){
      sum[i+1]=sum[i]+vec[i].second;
    }
	int idx= 0;
	for(int i = N-1; i >= 0; --i){
		if(p>vec[i].second)p-= vec[i].second;
		else {
			idx = i;
			break;
        }
    }
    ll lb = -1,ub = idx+1;
    while (ub-lb>1){
      ll mb = (ub+lb)/2;
      ll t = vec[mb].first + m;
      bool f = true;
      if(t>=vec[idx].first){
        ll rem = (v-sum[mb+1]-sum[N]+sum[idx+1])*m;
        for(int i = mb+1; i < idx+1; ++i){
          rem -= vec[i].second * min(m,t-vec[i].first);
        }
        if(rem>0)f=false;
      }
      else f = false;
      
      if(f) ub = mb;
      else lb = mb;
    }
    ll ans= 0;
    for(int i = ub; i < N; ++i)ans+= vec[i].second ;
    cout << ans << endl;
}
