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
  ll n;cin >>n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  
  if(a[0] != 0){
    cout << -1 << endl;
    return 0;
  }
  ll ans=0, top = a[n-1], now = a[n-1];
  for(int i = n-2; i >= 0; --i){
    if(a[i]==now-1){
      now=a[i];
    }
    else if(a[i]<now-1){
      cout << -1 << endl;
      return 0;
    }
    else{
      ans+=top;
      top=a[i];
      now=a[i];
    }
  }
  ans+=top;
  cout << ans<< endl;
}
