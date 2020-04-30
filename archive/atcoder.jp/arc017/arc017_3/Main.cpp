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
  ll n,x;cin >>n>>x;
  ll m = n/2;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i){
    cin >>a[i];
  }
  
  map<ll, ll> mp1, mp2;
  for(ll i = 0; i < (1LL<<m); ++i){
    bitset<16> bit(i);
    ll tmp = 0;
    for(int j = 0; j < m; ++j){
      if(bit[j]) tmp += a[j];
    }
    //cout << tmp << endl;
    ++mp1[tmp];
  }
  
  for(ll i = 0; i < (1LL<<(n-m)); ++i){
    bitset<16> bit(i);
    ll tmp = 0;
    for(int j = 0; j < (n-m); ++j){
      if(bit[j]) tmp += a[j+m];
    }
    //cout << tmp << endl;
    ++mp2[tmp];
  }
  ll ans = 0;
  for(auto it : mp1){
    ll k = it.first;
    ll num = it.second;
    ans+= num* mp2[x-k];
  }
  cout << ans << endl;
}
