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
  ll n,k;cin >>n>> k;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >>a[i];
  
  ll r=0,ans=0;
  for(ll l = 0; l < n;){
    for(r = l+1; r < n; ++r){
      if(a[r]<=a[r-1])break;
    }
    ans+=max(0LL,r-l-k+1);
    l=r;
  }
  cout << ans << endl;
}
