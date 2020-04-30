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
  ll n,k;cin >> n >> k;
  vector<ll> a(n), sum(n+1);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    --a[i];
    a[i]%=k;
    sum[i+1]=sum[i]+a[i];
    sum[i+1]%=k;
  }
  
  ll ans = 0;
  map<int, int> mp;
  for(int i = 0; i <= n; ++i){
    if(i>=k)--mp[sum[i-k]];
    ans += mp[sum[i]];
    ++mp[sum[i]];
  }
  cout << ans << endl;
}
