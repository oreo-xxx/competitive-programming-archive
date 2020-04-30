#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
	ll n;cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<ll> l(n), r(n),idx(n);
    for(int i = 0; i < n; ++i){
      int it1 = lower_bound(a.begin(), a.end(),2*a[i]) - a.begin();
      int it2 = upper_bound(a.begin(), a.end(),a[i]/2) - a.begin();
      r[i]= n-it1;
      idx[i]= it1;
      l[i]= it2;
    }
    vector<ll> rsum(n+1);
    for(int i = 0; i < n; ++i){
      rsum[i+1]= rsum[i]+ r[i];
      rsum[i+1]%= MOD;
    }
  
    ll ans = 0;
    for(int i = 0; i < n; ++i){
      ans+= l[i] * (rsum[n]-rsum[idx[i]]);
      ans%= MOD;
    }
    cout << ans << endl;
}
