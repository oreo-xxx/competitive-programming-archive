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
  for(int i = 0; i < n; ++i){cin>> a[i];}
  ll ans=0, tmp=0;
  for(int i = 0; i < k; ++i){
    tmp+=a[i];
  }
  ans+=tmp;
  for(int i = k; i < n; ++i){
    tmp+=a[i];
    tmp-=a[i-k];
    ans += tmp;
  }
  cout << ans << endl;
}
