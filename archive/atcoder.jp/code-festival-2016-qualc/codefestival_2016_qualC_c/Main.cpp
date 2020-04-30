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
  int n; cin >> n;
  vector<ll> t(n),a(n),fixed(n);
  ll M= 0;
  for(int i = 0; i < n; ++i){
    cin >> t[i];
    if(M<t[i]){
      M=t[i];
      fixed[i]=1;
    }
  }
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  M=0;
  bool f = true;
  for(int i = n-1; i >= 0; --i){
    if(fixed[i] && a[i] < t[i]){
      f = false;
    }
    if(M<a[i]){
      M=a[i];
      fixed[i]= 1;
    }
  }
  ll ans = 0;
  if(f)ans = 1;
  ll now = 0;
  for(int i = 0; i < n; ++i){
    if(fixed[i]){
      ;
    }
    else{
      ans *= min(a[i],t[i]);
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
