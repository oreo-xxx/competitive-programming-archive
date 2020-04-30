#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>;
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  ll n,t;cin >>n>> t;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >>a[i];
  
  ll s=0, now=0, ans=0;
  for(int i = 0; i < n; ++i){
    if(now+t>=a[i]){
      now=a[i];
    }
    else{
      ans+=now+t-s;
      s=a[i];
      now=a[i];
    }
  }
  ans+=now+t-s;
  cout << ans << endl;
}
